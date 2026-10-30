#include "customerAccounts.h"


customerAccounts::customerAccounts()
{
    accountNo = 0;
    customerName = "";
    address = "";
    suburb = "";
    propertyType = "";
    previousUsage = 0;
    currentUsage = 0;
    refuseBin = "";
}

customerAccounts::customerAccounts(int _accountNo, String^ _customerName, String^ _address, String^ _suburb,
    String^ _propertyType, int _previousUsage, int _currentUsage, String^ _refuseBin)
{
    this->accountNo = _accountNo;
    this->customerName = _customerName;
    this->address = _address;
    this->suburb = _suburb;
    this->propertyType = _propertyType;
    this->previousUsage = _previousUsage;
    this->currentUsage = _currentUsage;
    this->refuseBin = _refuseBin;
}

//setters

void customerAccounts::setAccountNo(int _accountNo)
{
    this->accountNo = _accountNo;
}

void customerAccounts::setCustomersName(String^ _customerName)
{
    this->customerName = _customerName;
}

void customerAccounts::setAddress(String^ _address)
{
    this->address = _address;
}

void customerAccounts::setSuburb(String^ _suburb)
{
    this->suburb = _suburb;
}

void customerAccounts::setPropertyType(String^ _propertyType)
{
    this->propertyType = _propertyType;
}

void customerAccounts::setPreviousUsage(int _previousUsage)
{
    this->previousUsage = _previousUsage;
}

void customerAccounts::setCurrentUsage(int _currentUsage)
{
    this->currentUsage = _currentUsage;
}

void customerAccounts::setRefuseBin(String^ _refuseBin)
{
    this->refuseBin = _refuseBin;
}

//getters

int customerAccounts::getAccountNo()
{
    return accountNo;
}

String^ customerAccounts::getCustomerName()
{
    return customerName;
}

String^ customerAccounts::getAddress()
{
    return address;
}

String^ customerAccounts::getSuburb()
{
    return suburb;
}

String^ customerAccounts::getPropertyType()
{
    return propertyType;
}

int customerAccounts::getPreviousUsage()
{
    return previousUsage;
}

int customerAccounts::getCurrentUsage()
{
    return currentUsage;
}

String^ customerAccounts::getRefuseBin()
{
    return refuseBin;
}

int customerAccounts::CalculateWaterConsumption()
{
    return currentUsage - previousUsage;
}

double customerAccounts::CalculateWaterCharge()
{
    int consumption = CalculateWaterConsumption();

    if (propertyType == "Business")
        return consumption * 52.05;
    else // Residential, Flats/Townhouses, Indigent
        return consumption * 38.21;
}

double customerAccounts::CalculateWasteCharge()
{
    if (propertyType == "Indigent")
    {
        return 111.44; // 50% of R222.88
    }
    else if (propertyType == "Residential" || propertyType == "Flats/Townhouses")
    {
        return 222.88;
    }
    else if (propertyType == "Business")
    {
        // Parse bin size
        int binSize;
        if (refuseBin == "240L Bin")
            binSize = 240;
        else if (refuseBin == "660L Bin")
            binSize = 660;
        else if (refuseBin == "900L Bin")
            binSize = 900;
        else
            binSize = 240; // default

        switch (binSize)
        {
        case 240: return 584.46;
        case 660: return 1754.76;
        case 900: return 2339.55;
        default: return 584.46;
        }
    }
    return 0;
}

double customerAccounts::CalculateSewerageCharge()
{
    int consumption = CalculateWaterConsumption();

    if (consumption <= 200)
        return consumption * 16.85;
    else if (consumption <= 2500)
        return consumption * 15.54;
    else
        return consumption * 13.61;
}

double customerAccounts::CalculateTotalAmount()
{
    return CalculateWaterCharge() + CalculateWasteCharge() + CalculateSewerageCharge();
}

String^ customerAccounts::GetBillSummary()
{
    int consumption = CalculateWaterConsumption();
    double waterCharge = CalculateWaterCharge();
    double wasteCharge = CalculateWasteCharge();
    double sewerageCharge = CalculateSewerageCharge();
    double total = CalculateTotalAmount();

    return String::Format("Account: {0}     |       {1}\r\n" + "     " +
        "Consumption: {2} kl     |      Water: R{3:F2}\r\n" + "      " +
        "Waste: R{4:F2}     |       Sewerage: R{5:F2}\r\n" + "       " +
        "TOTAL DUE: R{6:F2}\r\n",// +
        // "----------------------------------------",
        accountNo, customerName, consumption, waterCharge,
        wasteCharge, sewerageCharge, total);
}
