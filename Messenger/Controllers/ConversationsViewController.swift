//
//  ViewController.swift
//  Messenger
//
//  Created by Rave BizzDev on 6/13/20.
//  Copyright © 2020 Rave BizzDev. All rights reserved.
//

import UIKit
import FirebaseAuth

class ConversationsViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
//        view.backgroundColor = .red
        
//        DatabaseManager.shared.test()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
//        let isLoggedIn = UserDefaults.standard.bool(forKey: "logged_in")
        
        validateAuth()
        
    }
    
    func validateAuth() {
        if FirebaseAuth.Auth.auth().currentUser == nil {
            let vc = LoginViewController()
            let nav = UINavigationController(rootViewController: vc)
            nav.modalPresentationStyle = .fullScreen
            present(nav, animated: false)
        } 
    }

}

