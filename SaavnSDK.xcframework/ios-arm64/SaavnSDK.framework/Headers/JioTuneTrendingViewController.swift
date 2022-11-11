//
//  JioTuneTrendingViewController.swift
//  Saavn
//
//  Created by Gourav Kumar on 04/11/22.
//  Copyright © 2022 Saavn. All rights reserved.
//


import UIKit
 import Starscream

enum MoreJioTuneVCType{
    case moreTrendingJioTunes
    case moreSearchJioTunes
}

@objc public class JioTuneTrendingViewController: ListVC {
    var dataArray:[[String:Any]] = []
    let actInd = UIActivityIndicatorView()
    var defaultSocket = JioTuneWebSocket(apiEndpoint: "")
    var type: MoreJioTuneVCType = .moreTrendingJioTunes
    var query = ""
    
    public override func viewDidLoad() {
        super.viewDidLoad()
        viewType = ViewType_JIOTUNE
        isFetching = true
        initActivityIndicatory(parentView: view)
        setTitle()
        let newElement = [
            "title":     "",
            "subtitle":  "",
            "noHeader":  true,
            "type":      SectionType.Cells_Standard.rawValue,
            "contents":  []
        ] as [String : Any]
        dataArray.append(newElement)
        setupSocket()
    }
    
    private func setTitle(){
        switch type {
        case .moreTrendingJioTunes:
            title = "Trending JioTunes"
        case .moreSearchJioTunes:
            var queryDisplay = query
            if queryDisplay.count > 9 { queryDisplay = queryDisplay.prefix(9) + " ..." }
            title = "\(queryDisplay) Songs"
        }
    }
    
    private func setupSocket() {
        switch type {
        case .moreTrendingJioTunes:
            page = 1
            defaultSocket = JioTuneWebSocket(apiEndpoint: "jiotunepage.getMoreTrendingSongs")
        case .moreSearchJioTunes:
            page = 1
            defaultSocket = JioTuneWebSocket(apiEndpoint: "jiotunepage.getMoreSongs")
        }
        defaultSocket.delegate = self
        defaultSocket.setupSocket()
        defaultSocket.startRequest(with: query, artistId: nil)
        defaultSocket.fetchData(for: .first)
    }
    
    private func initActivityIndicatory(parentView: UIView) {
        actInd.center = parentView.center
        actInd.hidesWhenStopped = true
        actInd.style = UIActivityIndicatorView.Style.gray
        actInd.tintColor = Styles_n.fillColor()
        parentView.addSubview(actInd)
        actInd.startAnimating()
    }
    
    public override func fetchData(forPage thePage: UInt) {
        isFetching = true
        page += 1
        switch type {
        case .moreTrendingJioTunes:
            defaultSocket.fetchData(for: .next)
        case .moreSearchJioTunes:
            defaultSocket.fetchData(for: .next)
        }
    }
    
    private func initData(data: [String:Any]) {
        if let re = (data["resp"]),
           let data = (re as? String)?.data(using: .utf8),
           let jsonData = try? JSONSerialization.jsonObject(with: data, options: .allowFragments),
           let resp = jsonData as? [String: Any] {
            
            let results = resp["results"] as? [[String:Any]] ?? []
            var contents = dataArray[0]["contents"] as! [[String: Any]]
            contents.append(contentsOf: results)
            dataArray[0]["contents"] = contents
            groupData = NSMutableArray(array: dataArray)
            Layout.cacheHeights(groupData as? [Any], forVC: self)
            mainTable.reloadData()
        }
    }
}

extension JioTuneTrendingViewController: WebSocketDelegate{
    public func websocketDidConnect(socket: WebSocketClient) {
        defaultSocket.startRequest(with: query, artistId: nil)
        defaultSocket.fetchData(for: .first)
        isFetching = true
    }
    
    public func websocketDidDisconnect(socket: WebSocketClient, error: Error?) {
        actInd.stopAnimating()
    }
    
    public func websocketDidReceiveMessage(socket: WebSocketClient, text: String) {
        actInd.stopAnimating()
        isFetching = false
        guard let data = text.data(using: .utf8),
              let jsonData = try? JSONSerialization.jsonObject(with: data),
              let jsonDict = jsonData as? [String: Any] else {
            return
        }
        //        print("page: ",page, "data: ",jsonDict)
        initData(data: jsonDict)
    }
    
    public func websocketDidReceiveData(socket: WebSocketClient, data: Data) {
        
    }
}

extension JioTuneTrendingViewController{
    public override func getScreenName() -> String! {
        return "trending_jiotune_page_screen"
    }
}


