<?php

declare(strict_types=1);

namespace Components;

use Models\User;
use PDO;
use PDOStatement;

class Database
{
    public $pdo;

    private function __construct()
    {
        $dsn = "mysql:host=localhost;port=3306;dbname=bootstrapdb;charset=utf8mb4";
        $options = [
            PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        ];
        $this->pdo = new PDO($dsn, "phpuser", "4K2#f%[&u!+5M[M{", $options);
    }

    /* Return the same instance of Database when this method is invoked (the singleton pattern) */
    public static function instance()
    {
        static $instance;
        if (is_null($instance)) {
            $instance = new static();
        }
        return $instance;
    }

    /* create table users (
    -> id int not null primary key auto_increment,
    -> username varchar(10) not null unique,
    -> password varchar(60) not null,
    -> signup_time datetime default current_timestamp not null);

    password varchar(60) becoz hashed password is saved

    */
    public function addUser(string $username, string $password): PDOStatement
    {
        $stmt = $this->pdo->prepare("insert into users (username, password) values (:user, :pass)");
        $stmt->execute([
            ':user' => $username,
            ':pass' => password_hash($password, PASSWORD_BCRYPT),
        ]);
        return $stmt;
    }

    public function getUserByUsername(string $formUsername): ?User
    {
        $stmt = $this->pdo->prepare("select * from users where username = :username");
        /* 
            $sth = $dbh->prepare("SELECT name, colour FROM fruit");
            $sth->execute();
            $result = $sth->fetch(PDO::FETCH_ASSOC);
            print_r($result);
            PDO::FETCH_ASSOC: Return next row as an array indexed by column name
            Array
            (
                [name] => apple
                [colour] => red
            )
        */
        if ($stmt->execute([':username' => $formUsername]) && ($data = $stmt->fetch(PDO::FETCH_ASSOC))) {
            return new User($data);
        }
        return null;
    }

    public function getUserById(int $id): ?User
    {
        $stmt = $this->pdo->prepare("select * from users where id = :id");
        $stmt->bindParam(':id', $id, PDO::PARAM_INT);
        /* Since we binded $id to ':id' using bindParam
            So, that's why we didn't do $stmt->execute([':id' => $id])
        */
        if ($stmt->execute() && ($data = $stmt->fetch(PDO::FETCH_ASSOC))) {
            return new User($data);
        }
        return null;
    }

    public function getOwnContacts(int $uid): PDOStatement
    {
        $stmt = $this->pdo->prepare("select * from contacts where user_id = :uid");
        $stmt->bindParam(':uid', $uid, PDO::PARAM_INT);
        $stmt->execute();
        return $stmt;
    }

    public function getOwnContactById(int $ownerId, int $contactId): ?array
    {
        $stmt = $this->pdo->prepare("select * from contacts where id = :cid and user_id = :uid");
        $stmt->bindParam(':cid', $contactId, PDO::PARAM_INT);
        $stmt->bindParam(':uid', $ownerId, PDO::PARAM_INT);
        if ($stmt->execute() && ($data = $stmt->fetch(PDO::FETCH_ASSOC))) {
            return $data;
        }
        return null;
    }

    /* 
    create table contacts( id int not null primary key auto_increment,
                user_id int not null,
                name varchar(20) not null,
                phone varchar(20) not null,
                email varchar(50) not null unique,
                address varchar(300) not null,
                foreign key (user_id) references users(id)
        );
    */
    public function addContact(
        int $ownerId,
        string $name,
        string $email,
        string $phone,
        string $address
    ): PDOStatement {
        $stmt = $this->pdo->prepare("insert into contacts (user_id, name, phone, email, address) " .
            "values (:uid, :name, :phone, :email, :address)");
        $stmt->bindParam(':uid', $ownerId, PDO::PARAM_INT);
        /* Default $type = PDO::PARAM_STR */
        $stmt->bindParam(':name', $name);
        $stmt->bindParam(':phone', $phone);
        $stmt->bindParam(':email', $email);
        $stmt->bindParam(':address', $address);
        $stmt->execute();
        return $stmt;
    }

    public function updateContact(
        int $contactId,
        int $ownerId,
        string $name,
        string $email,
        string $phone,
        string $address
    ): PDOStatement {
        $stmt = $this->pdo->prepare(
            "update contacts set name = :name, phone = :phone, email = :email, address = :address "
                . "where id = :cid and user_id = :uid"
        );
        $stmt->bindParam(':cid', $contactId, PDO::PARAM_INT);
        $stmt->bindParam(':uid', $ownerId, PDO::PARAM_INT);
        $stmt->bindParam(':name', $name);
        $stmt->bindParam(':phone', $phone);
        $stmt->bindParam(':email', $email);
        $stmt->bindParam(':address', $address);
        $stmt->execute();
        return $stmt;
    }

    public function deleteOwnContactById(int $ownerId, int $contactId): PDOStatement
    {
        $stmt = $this->pdo->prepare("delete from contacts where id = :cid and user_id = :uid");
        $stmt->bindParam(':cid', $contactId, PDO::PARAM_INT);
        $stmt->bindParam(':uid', $ownerId, PDO::PARAM_INT);
        $stmt->execute();
        return $stmt;
    }
}
