#pragma once
using namespace System;


ref class customerAccounts
{
private:
    int accountNo;
    String^ customerName;
    String^ address;
    String^ suburb;
    String^ propertyType;
    int previousUsage;
    int currentUsage;
    String^ refuseBin;

public:
    customerAccounts();
    customerAccounts(int _accountNo, String^ _customerName, String^ _address, String^ _suburb, String^ _propertyType,
        int _previousUsage, int _currentUsage, String^ _refuseBin);

    //setters
    void setAccountNo(int _accountNo);
    void setCustomersName(String^ _customerName);
    void setAddress(String^ _address);
    void setSuburb(String^ _suburb);
    void setPropertyType(String^ _propertyType);
    void setPreviousUsage(int _previousUsage);
    void setCurrentUsage(int _currentUsage);
    void setRefuseBin(String^ _refuseBin);

    //getters
    int getAccountNo();
    String^ getCustomerName();
    String^ getAddress();
    String^ getSuburb();
    String^ getPropertyType();
    int getPreviousUsage();
    int getCurrentUsage();
    String^ getRefuseBin();

    // Calculation methods
    int CalculateWaterConsumption();
    double CalculateWaterCharge();
    double CalculateWasteCharge();
    double CalculateSewerageCharge();
    double CalculateTotalAmount();

    // Display method
    String^ GetBillSummary();

};
