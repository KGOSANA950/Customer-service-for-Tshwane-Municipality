#include "services.h"
#include "customerAccounts.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace customerServices;   // must match the namespace in services.h
using namespace System::IO;
using namespace System::Collections::Generic;

array< customerAccounts^>^ loadCustomerAccounts(String^ filename)
{
    List< customerAccounts^>^ tempList = gcnew List< customerAccounts^>();
    try
    {
        StreamReader^ read = gcnew StreamReader(filename);
        String^ line;

        //skip the header
        read->ReadLine();

        while ((line = read->ReadLine()) != nullptr)
        {
            array<String^>^ parts = line->Split(',');

            customerAccounts^ r = gcnew customerAccounts();

            r->setAccountNo(Convert::ToInt32(parts[0]));
            r->setCustomersName(parts[1]);
            r->setAddress(parts[2]);
            r->setSuburb(parts[3]);
            r->setPropertyType(parts[4]);
            r->setPreviousUsage(Convert::ToInt32(parts[5]));
            r->setCurrentUsage(Convert::ToInt32(parts[6]));
            r->setRefuseBin(parts[7]);

            tempList->Add(r);
        }

        read->Close();
        delete read;  // Release resources

    }
    catch (Exception^ e)
    {
        // Handle error if needed
        MessageBox::Show("Error reading file: " + e->Message);
    }
 

    return tempList->ToArray();

}


[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew services());
}
