package com.example.q13;

public class Customer {
    String _id;
    String name, address, phoneNumber;

    Customer(String _id, String name, String address, String phoneNumber) {
        this._id = _id;
        this.name = name;
        this.address = address;
        this.phoneNumber = phoneNumber;
    }

    public String get_id() {
        return _id;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }
}
