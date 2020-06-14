//
//  DatabaseManager.swift
//  Messenger
//
//  Created by Rave BizzDev on 6/14/20.
//  Copyright © 2020 Rave BizzDev. All rights reserved.
//

import Foundation
import FirebaseDatabase

//final means no subclass can inherit from this class
final class DatabaseManager {
    
    
    //Singleton
    static let shared = DatabaseManager()
    
    private let database = Database.database().reference()
    
}

//Mark: - Account Managment

extension DatabaseManager {
    
    public func userExists(with email: String, completion: @escaping ((Bool) -> Void)) {
        
        database.child(email).observeSingleEvent(of: .value) { (snapshot) in
            guard snapshot.value as? String != nil else { return }
            completion(true)
        }
    }
    
    /// Insert new user to database
    public func insertUser(with user: ChatAppUser) {
        database.child(user.emailAddress).setValue([
            "first_name": user.firstName,
            "last_name": user.lastName
        ])
    }
}

struct ChatAppUser {
    let firstName: String
    let lastName: String
    let emailAddress: String
//    let profilePictureUrl: String
}
