//
//  ModuleCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 27/07/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

class ModuleCell {
    let id: String
    let title: String
    let subTitle: String
    let imageLink: String?
    let squareImageLink: String?
    let type: ContentType
    let moreInfo: MoreInfo?
    let cellType: CellType
    let hideMeta: Bool
    let isExplicit: Bool
    var availability: Availability {
        if type != .episode && type != .song { return .available }
        if moreInfo?.rights?.reason.lowercased() == "pro only" { return .proOnly }
        if isExplicit && Settings.singleton()!.disableExplicit { return .expilictOff }
        if moreInfo?.rights?.code != 0 { return .unavailable }
        return .available
    }
    var isPlaying: Bool {
        let playingSongDict = PlayerLogic.singleton()?.getNowPlaying()
        let currentSongId = playingSongDict?["id"] as? String ?? ""
        return id == currentSongId
    }
    var playingState: BadgeView.PlayState {
        let episodePlayState = BookmarkManager.shared()?.getPlayState(forBookmarkEntry: id)
        let currentState = Int(episodePlayState?.rawValue ?? 0)
        return BadgeView.PlayState(rawValue: currentState) ?? .none
    }
    var cachable: Bool {
        let userData = UserData.getSingleton()!
        return !userData.isFreemium && UserData.canDownload() && userData.loggedIn && moreInfo?.rights?.cacheable ?? false
    }
    // OldCode Support
    let originalJSON: [AnyHashable: Any]
    
    init(_ dict: [String: Any], cellType: CellType) {
        id = dict["id"] as? String ?? ""
		title = (dict["title"] as? String ?? "").htmlDecoded
		subTitle = (dict["subtitle"] as? String ?? "").htmlDecoded
        imageLink = (dict["image"] ?? dict["image_url"] ?? dict["image_file_url"]) as? String
        squareImageLink = dict["square_image_url"] as? String
        type = ContentType(rawValue: dict["type"] as? String ?? "") ?? .other
        moreInfo = MoreInfo(dict["more_info"] as? [String: Any])
        self.cellType = cellType
        hideMeta = dict["hideMeta"] as? Bool ?? false
        isExplicit = (dict["explicit_content"] as? String).boolValue
        originalJSON = dict
    }
    
    func attributedSubTitle(for font: UIFont) -> NSAttributedString {
        let subTitleStr = NSMutableAttributedString(string: subTitle)
#if !__SvnSenSDK
        if isExplicit, (type == .song || type == .episode) {
            subTitleStr.show(Tag_Explicit, for: font)
        }
#endif
        return subTitleStr
    }
}


//MARK:- Enums
extension ModuleCell {
    enum Availability {
        case available, proOnly, unavailable, expilictOff
        var sideMessage: String? {
            switch self {
            case .proOnly: return "Pro Only"
            case .unavailable: return "UnAvailable"
            case .expilictOff: return "explicitOff"
            default: return nil
            }
        }
    }
}

struct MoreInfo {
    let backgroundColor: String?
    let squareImageLink: String?
    let description: String
    let showId: String
    let rights: Rights?
    let shortVideos: ShortVideosInfo?
    let artistMap: ArtistMap?
    let proOnly: Bool? // For Radio Station
    let thumbnailUrl: String?
    let gradientColorsArray: [UIColor]?
    let videoRateCap: Int?
    let previewUrl: String?
    let videoAvailable: Bool?
    let subTypes: [String]?
    let songMappings:[String]?
    let videoMappings:[String]?
    let contentCategory: String?
    init?(_ dict: [String: Any]?) {
        guard let dict = dict else { return nil }
        backgroundColor = dict["bg_color"] as? String
        squareImageLink = (dict["square_image"] ?? dict["square_image_url"]) as? String
        description = dict["description"] as? String ?? ""
        showId = dict["show_id"] as? String ?? ""
        rights = Rights(dict["rights"] as? [String: Any])
        let shortVideosArray = dict["third_party_videos"] as? [[String: Any]]
        shortVideos = ShortVideosInfo(shortVideosArray?.first)
        artistMap = ArtistMap(dict["artistMap"] as? [String: Any])
        proOnly = dict["pro_only"] as? Bool
        thumbnailUrl = dict["thumbnail_url"] as? String
        let gradientColors = dict["color"] as? String ?? ""
        gradientColorsArray = gradientColors.components(separatedBy: "|")
                                            .map { $0.hexColor ?? .white }
        videoRateCap = dict["video_rate_cap"] as? Int
        previewUrl = dict["preview_url"] as? String
        videoAvailable = dict["video_available"] as? Bool
        subTypes = dict["sub_types"] as? [String]
        songMappings = dict["song_mappings"] as? [String]
        videoMappings = dict["video_mappings"] as? [String]
        contentCategory = dict["content_category"] as? String
    }
}

struct Rights {
    let code: Int // If code is 1 then content is hidden(can be pro_only or unavailable reason)
    let reason: String
    let cacheable: Bool
    
    init?(_ dict: [String: Any]?) {
        guard let dict = dict else { return nil }
        code = dict["code"] as? Int ?? 0
        reason = dict["reason"] as? String ?? ""
        cacheable = (dict["cacheable"] as? String)?.boolValue ?? false
    }
}

struct ShortVideosInfo {
    let name: String
    let userImage: String
    let profileLink: URL?
	let image: String
    let language: String
    let partnerId: String
    let videoId: String
    let mediaUrl: String
	// OldCode Support
	let originalJSON: [AnyHashable: Any]
    
    init?(_ dict: [String: Any]?) {
        guard let dict = dict else { return nil }
		name = (dict["user_name"] as? String ?? "").htmlDecoded
        userImage = dict["user_image"] as? String ?? ""
        let userURL = dict["user_url"] as? String ?? ""
		image = dict["image"] as? String ?? ""
        profileLink = URL(string: userURL)
        language = dict["language"] as? String ?? ""
        partnerId = dict["partner_id"] as? String ?? ""
        videoId = dict["video_id"] as? String ?? ""
        mediaUrl = dict["Media_url"] as? String ?? ""
		originalJSON = dict
    }
}

struct ArtistMap {
    var primaryArtists: [ArtistInfo] = []
    var featuredArtists: [ArtistInfo] = []
    var artists: [ArtistInfo] = []
    
    init?(_ dict: [String: Any]?) {
        guard let dict = dict else { return nil }
        
        if let primaryArtistsData = dict["primary_artists"] as? [[String: Any]]{
            for artistData in primaryArtistsData {
                if let artist = ArtistInfo(artistData){
                    primaryArtists.append(artist)
                }
            }
        }
        if let featuredArtistsData = dict["featured_artists"] as? [[String: Any]]{
            for artistData in featuredArtistsData {
                if let artist = ArtistInfo(artistData){
                    featuredArtists.append(artist)
                }
            }
        }

        if let artistsData = dict["artists"] as? [[String: Any]]{
            for artistData in artistsData {
                if let artist = ArtistInfo(artistData){
                    artists.append(artist)
                }
            }
        }

    }
}

struct ArtistInfo {
    let id: String
    let name: String
    let role: String
    let image: String
    let type: String
    let permaUrl: String

    init?(_ dict: [String: Any]?) {
        guard let dict = dict else { return nil }
        id = dict["id"] as? String ?? ""
        name = dict["name"] as? String ?? ""
        role = dict["role"] as? String ?? ""
        image = dict["image"] as? String ?? ""
        type = dict["type"] as? String ?? ""
        permaUrl = dict["perma_url"] as? String ?? ""
    }
}




