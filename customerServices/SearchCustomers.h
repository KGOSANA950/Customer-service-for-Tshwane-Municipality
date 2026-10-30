#pragma once
#include "customerAccounts.h"
//#include <System::Collections::Generic::List.h>
using namespace System::Collections::Generic;

namespace customerServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SearchCustomers
	/// </summary>
	public ref class SearchCustomers : public System::Windows::Forms::Form
	{
	public:
		SearchCustomers(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		SearchCustomers(List<customerAccounts^>^ accountList)
		{
			
			InitializeComponent();
			accounts = accountList;
			this->Text = "Search Customers";
			rbAccountNo->Checked = true;  // Set default search type
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SearchCustomers()
		{
			if (components)
			{
				delete components;
			}
		}
		
	private: System::Windows::Forms::Button^ btnSearch;
	protected:List<customerAccounts^>^ accounts;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ rbAccountNo;
	private: System::Windows::Forms::RadioButton^ rbName;
	private: System::Windows::Forms::RadioButton^ rbAddress;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::ListBox^ lstResults;
	private: System::Windows::Forms::Label^ lblResultCount;








	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SearchCustomers::typeid));
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rbAccountNo = (gcnew System::Windows::Forms::RadioButton());
			this->rbName = (gcnew System::Windows::Forms::RadioButton());
			this->rbAddress = (gcnew System::Windows::Forms::RadioButton());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->lstResults = (gcnew System::Windows::Forms::ListBox());
			this->lblResultCount = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(369, 346);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(117, 46);
			this->btnSearch->TabIndex = 0;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &SearchCustomers::btnSearch_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(197, 346);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(117, 46);
			this->btnClose->TabIndex = 1;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &SearchCustomers::btnClose_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(35, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search";
			this->label1->Click += gcnew System::EventHandler(this, &SearchCustomers::label1_Click_1);
			// 
			// rbAccountNo
			// 
			this->rbAccountNo->AutoSize = true;
			this->rbAccountNo->Location = System::Drawing::Point(38, 81);
			this->rbAccountNo->Name = L"rbAccountNo";
			this->rbAccountNo->Size = System::Drawing::Size(94, 20);
			this->rbAccountNo->TabIndex = 3;
			this->rbAccountNo->TabStop = true;
			this->rbAccountNo->Text = L"AccountNo";
			this->rbAccountNo->UseVisualStyleBackColor = true;
			// 
			// rbName
			// 
			this->rbName->AutoSize = true;
			this->rbName->Location = System::Drawing::Point(219, 81);
			this->rbName->Name = L"rbName";
			this->rbName->Size = System::Drawing::Size(65, 20);
			this->rbName->TabIndex = 4;
			this->rbName->TabStop = true;
			this->rbName->Text = L"Name";
			this->rbName->UseVisualStyleBackColor = true;
			// 
			// rbAddress
			// 
			this->rbAddress->AutoSize = true;
			this->rbAddress->Location = System::Drawing::Point(386, 81);
			this->rbAddress->Name = L"rbAddress";
			this->rbAddress->Size = System::Drawing::Size(79, 20);
			this->rbAddress->TabIndex = 5;
			this->rbAddress->TabStop = true;
			this->rbAddress->Text = L"Address";
			this->rbAddress->UseVisualStyleBackColor = true;
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(219, 29);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(267, 22);
			this->txtSearch->TabIndex = 6;
			// 
			// lstResults
			// 
			this->lstResults->FormattingEnabled = true;
			this->lstResults->ItemHeight = 16;
			this->lstResults->Location = System::Drawing::Point(38, 135);
			this->lstResults->Name = L"lstResults";
			this->lstResults->Size = System::Drawing::Size(448, 180);
			this->lstResults->TabIndex = 7;
			// 
			// lblResultCount
			// 
			this->lblResultCount->AutoSize = true;
			this->lblResultCount->Location = System::Drawing::Point(35, 361);
			this->lblResultCount->Name = L"lblResultCount";
			this->lblResultCount->Size = System::Drawing::Size(79, 16);
			this->lblResultCount->TabIndex = 8;
			this->lblResultCount->Text = L"ResultCount";
			// 
			// SearchCustomers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(534, 416);
			this->Controls->Add(this->lblResultCount);
			this->Controls->Add(this->lstResults);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->rbAddress);
			this->Controls->Add(this->rbName);
			this->Controls->Add(this->rbAccountNo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSearch);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SearchCustomers";
			this->Text = L"SearchCustomers";
			this->Load += gcnew System::EventHandler(this, &SearchCustomers::SearchCustomers_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e)
			{

			}
	
		private: System::Void SearchCustomers_Load(System::Object^ sender, System::EventArgs^ e)
		{

		}

		private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				// Clear previous results
				lstResults->Items->Clear();

				String^ searchTerm = txtSearch->Text->Trim();

				if (String::IsNullOrWhiteSpace(searchTerm))
				{
					MessageBox::Show("Please enter a search term.", "Search",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				int matchCount = 0;

				// Search by Account No
				if (rbAccountNo->Checked)
				{
					int accNo;
					if (Int32::TryParse(searchTerm, accNo))
					{
						for each (customerAccounts ^ acc in accounts)
						{
							if (acc->getAccountNo() == accNo)
							{
								matchCount++;
								lstResults->Items->Add("Account No: " + acc->getAccountNo());
								lstResults->Items->Add("Name: " + acc->getCustomerName());
								lstResults->Items->Add("Address: " + acc->getAddress());
								lstResults->Items->Add("Suburb: " + acc->getSuburb());
								lstResults->Items->Add("Property Type: " + acc->getPropertyType());
								lstResults->Items->Add("Previous Usage: " + acc->getPreviousUsage());
								lstResults->Items->Add("Current Usage: " + acc->getCurrentUsage());
								lstResults->Items->Add("Refuse Bin: " + acc->getRefuseBin());
								lstResults->Items->Add("----------------------------------------");
							}
						}
					}
					else
					{
						MessageBox::Show("Please enter a valid Account Number.", "Search",
							MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
				}
				// Search by Customer Name
				else if (rbName->Checked)
				{
					for each (customerAccounts ^ acc in accounts)
					{
						if (acc->getCustomerName()->ToLower()->Contains(searchTerm->ToLower()))
						{
							matchCount++;
							lstResults->Items->Add("Account No: " + acc->getAccountNo());
							lstResults->Items->Add("Name: " + acc->getCustomerName());
							lstResults->Items->Add("Address: " + acc->getAddress());
							lstResults->Items->Add("Suburb: " + acc->getSuburb());
							lstResults->Items->Add("Property Type: " + acc->getPropertyType());
							lstResults->Items->Add("Previous Usage: " + acc->getPreviousUsage());
							lstResults->Items->Add("Current Usage: " + acc->getCurrentUsage());
							lstResults->Items->Add("Refuse Bin: " + acc->getRefuseBin());
							lstResults->Items->Add("----------------------------------------");
						}
					}
				}
				// Search by Address
				else if (rbAddress->Checked)
				{
					for each (customerAccounts ^ acc in accounts)
					{
						if (acc->getAddress()->ToLower()->Contains(searchTerm->ToLower()) ||
							acc->getSuburb()->ToLower()->Contains(searchTerm->ToLower()))
						{
							matchCount++;
							lstResults->Items->Add("Account No: " + acc->getAccountNo());
							lstResults->Items->Add("Name: " + acc->getCustomerName());
							lstResults->Items->Add("Address: " + acc->getAddress());
							lstResults->Items->Add("Suburb: " + acc->getSuburb());
							lstResults->Items->Add("Property Type: " + acc->getPropertyType());
							lstResults->Items->Add("Previous Usage: " + acc->getPreviousUsage());
							lstResults->Items->Add("Current Usage: " + acc->getCurrentUsage());
							lstResults->Items->Add("Refuse Bin: " + acc->getRefuseBin());
							lstResults->Items->Add("----------------------------------------");
						}
					}
				}

				// Show result count
				if (matchCount > 0)
				{
					lblResultCount->Text = "Found " + matchCount + " customer(s)";
				}
				else
				{
					lblResultCount->Text = "No matching customers found";
					MessageBox::Show("No matching customers found.", "Search Results",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error searching: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e)
		{

		}

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		private: System::Void lblResults_DoubleClick(System::Object^ sender, System::EventArgs^ e)
		{

		}
};
}
