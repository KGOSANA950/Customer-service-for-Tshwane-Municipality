#pragma once
// Include the full header
#include "customerAccounts.h"
#include "AddEditForm.h"
#include "SearchCustomers.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;


array<customerAccounts^>^ loadCustomerAccounts(String^ filename);

namespace customerServices {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;		//for dialogresult
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for services
	/// </summary>
	public ref class services : public System::Windows::Forms::Form
	{
	public:
		services(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			accounts = gcnew List<customerAccounts^>();  // Initialize the list
		}
		//List<customerAccounts^>^ accounts;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~services()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
		List<customerAccounts^>^ accounts;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ updateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ searchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ lstDisplay;

	private: System::Windows::Forms::Button^ btnClearDisplay;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnSummary;
	private: System::Windows::Forms::ToolStripMenuItem^ accountNoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ customerNameToolStripMenuItem;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(services::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->accountNoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customerNameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lstDisplay = (gcnew System::Windows::Forms::ListBox());
			this->btnClearDisplay = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnSummary = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->viewToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1494, 38);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &services::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 34);
			this->fileToolStripMenuItem->Text = L"&File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::fileToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addToolStripMenuItem,
					this->deleteToolStripMenuItem, this->updateToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(49, 34);
			this->editToolStripMenuItem->Text = L"&Edit";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(141, 26);
			this->addToolStripMenuItem->Text = L"&Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::addToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(141, 26);
			this->deleteToolStripMenuItem->Text = L"&Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::deleteToolStripMenuItem_Click);
			// 
			// updateToolStripMenuItem
			// 
			this->updateToolStripMenuItem->Name = L"updateToolStripMenuItem";
			this->updateToolStripMenuItem->Size = System::Drawing::Size(141, 26);
			this->updateToolStripMenuItem->Text = L"&Update";
			this->updateToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::updateToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->searchToolStripMenuItem,
					this->sortToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(55, 34);
			this->viewToolStripMenuItem->Text = L"&View";
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->searchToolStripMenuItem->Text = L"&Search";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::searchToolStripMenuItem_Click);
			// 
			// sortToolStripMenuItem
			// 
			this->sortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->accountNoToolStripMenuItem,
					this->customerNameToolStripMenuItem
			});
			this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
			this->sortToolStripMenuItem->Size = System::Drawing::Size(136, 26);
			this->sortToolStripMenuItem->Text = L"&Sort";
			// 
			// accountNoToolStripMenuItem
			// 
			this->accountNoToolStripMenuItem->Name = L"accountNoToolStripMenuItem";
			this->accountNoToolStripMenuItem->Size = System::Drawing::Size(195, 26);
			this->accountNoToolStripMenuItem->Text = L"AccountNo";
			this->accountNoToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::accountNoToolStripMenuItem_Click);
			// 
			// customerNameToolStripMenuItem
			// 
			this->customerNameToolStripMenuItem->Name = L"customerNameToolStripMenuItem";
			this->customerNameToolStripMenuItem->Size = System::Drawing::Size(195, 26);
			this->customerNameToolStripMenuItem->Text = L"CustomerName";
			this->customerNameToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::customerNameToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 34);
			this->helpToolStripMenuItem->Text = L"&Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &services::aboutToolStripMenuItem_Click);
			// 
			// lstDisplay
			// 
			this->lstDisplay->FormattingEnabled = true;
			this->lstDisplay->ItemHeight = 16;
			this->lstDisplay->Location = System::Drawing::Point(22, 69);
			this->lstDisplay->Name = L"lstDisplay";
			this->lstDisplay->Size = System::Drawing::Size(1110, 388);
			this->lstDisplay->TabIndex = 1;
			this->lstDisplay->SelectedIndexChanged += gcnew System::EventHandler(this, &services::lstDisplay_SelectedIndexChanged);
			this->lstDisplay->DoubleClick += gcnew System::EventHandler(this, &services::lstDisplay_DoubleClick);
			// 
			// btnClearDisplay
			// 
			this->btnClearDisplay->Location = System::Drawing::Point(850, 514);
			this->btnClearDisplay->Name = L"btnClearDisplay";
			this->btnClearDisplay->Size = System::Drawing::Size(144, 44);
			this->btnClearDisplay->TabIndex = 2;
			this->btnClearDisplay->Text = L"Clear";
			this->btnClearDisplay->UseVisualStyleBackColor = true;
			this->btnClearDisplay->Click += gcnew System::EventHandler(this, &services::btnClearDisplay_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(38, 629);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(940, 44);
			this->progressBar1->TabIndex = 3;
			// 
			// btnSummary
			// 
			this->btnSummary->Location = System::Drawing::Point(643, 514);
			this->btnSummary->Name = L"btnSummary";
			this->btnSummary->Size = System::Drawing::Size(144, 44);
			this->btnSummary->TabIndex = 4;
			this->btnSummary->Text = L"Summary";
			this->btnSummary->UseVisualStyleBackColor = true;
			this->btnSummary->Click += gcnew System::EventHandler(this, &services::btnSummary_Click);
			// 
			// services
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1195, 704);
			this->Controls->Add(this->btnSummary);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->btnClearDisplay);
			this->Controls->Add(this->lstDisplay);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"services";
			this->Text = L"services";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
			{
				System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
					"Are you sure you want to exit?",
					"Confirm Exit",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Warning
				);

				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					Application::Exit();
				}
			}

		private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try
			{
				// Use a fixed filename - change this to your actual file path
				String^ filename = "services.csv";



				// Call the function to load accounts from the file
				array<customerAccounts^>^ loadedAccounts = loadCustomerAccounts(filename);

				// Clear the existing items in listbox and accounts collection
				lstDisplay->Items->Clear();
				accounts->Clear();  // Clear the accounts collection

				// Check if we got any accounts
				if (loadedAccounts != nullptr && loadedAccounts->Length > 0)
				{
					// Loop through each loaded account
					for (int i = 0; i < loadedAccounts->Length; i++)
					{
						customerAccounts^ account = loadedAccounts[i];

						// Add to the accounts collection for later use
						accounts->Add(account);

						// Add the bill summary to the listbox for display
						//lstDisplay->Items->Add(account->GetBillSummary());
						lstDisplay->Items->Add(account->getAccountNo()+ " --- " + account->getCustomerName() + " --- " + account->getAddress()+ " --- "
							+ " --- "+ account->getSuburb() + " --- " + account->getPropertyType() + " --- " + 
						account->getPreviousUsage() + " --- "+ account->getCurrentUsage() + " --- " + account->getRefuseBin());
					}

					// Show success message with count
					MessageBox::Show("Successfully loaded " + loadedAccounts->Length + " accounts from " + filename,
						"Load Successful", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					MessageBox::Show("No accounts found in " + filename + " or file doesn't exist.",
						"Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex)
			{
				// Show error message if something went wrong
				MessageBox::Show("Error loading file: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void btnClearDisplay_Click(System::Object^ sender, System::EventArgs^ e)
		{
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
				"Are you sure you want to Clear ListBox?",
				"Confirm Exit",
				System::Windows::Forms::MessageBoxButtons::YesNo,
				System::Windows::Forms::MessageBoxIcon::Question
			);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				lstDisplay->Items->Clear();
			}
		}

		private: System::Void btnSummary_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//clear the listbox
			lstDisplay->Items->Clear();

			// Call the function to load accounts from the file
			array<customerAccounts^>^ loadedAccounts = loadCustomerAccounts("services.csv");

			// Loop through each loaded account
			for (int i = 0; i < loadedAccounts->Length; i++)
			{
				customerAccounts^ account = loadedAccounts[i];

				// Add to the accounts collection for later use
				accounts->Add(account);

				// Add the bill summary to the listbox for display
				lstDisplay->Items->Add(account->GetBillSummary());

			}
		}
		private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{

		}

		private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//try
			//{
			//	// Use the same filename you used for opening
			//	String^ filename = "services.csv";

			//	// Check if there are accounts to save
			//	if (accounts->Count == 0)
			//	{
			//		MessageBox::Show("No accounts to save.", "Information",
			//			MessageBoxButtons::OK, MessageBoxIcon::Information);
			//		return;
			//	}

			//	// Create a StreamWriter to write to the file
			//	StreamWriter^ writer = gcnew StreamWriter(filename);

			//	// Write each account to the file
			//	for each (customerAccounts ^ account in accounts)
			//	{
			//		// Format: AccountNo,CustomerName,Address,Suburb,PropertyType,PreviousUsage,CurrentUsage,RefuseBin
			//		String^ line = account->getAccountNo().ToString() + "," +
			//			account->getCustomerName() + "," +
			//			account->getAddress() + "," +
			//			account->getSuburb() + "," +
			//			account->getPropertyType() + "," +
			//			account->getPreviousUsage().ToString() + "," +
			//			account->getCurrentUsage().ToString() + "," +
			//			account->getRefuseBin();

			//		writer->WriteLine(line);
			//	}

			//	// Close the writer
			//	writer->Close();


			//	MessageBox::Show("Successfully saved " + accounts->Count + " accounts to " + filename,
			//		"Save Successful", MessageBoxButtons::OK, MessageBoxIcon::Information);
			//}
			//catch (Exception^ ex)
			//{
			//	MessageBox::Show("Error saving file: " + ex->Message,
			//		"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			//}

			try
			{
				// Use the same filename you used for opening
				String^ filename = "services.csv";

				// Check if there are accounts to save
				if (accounts->Count == 0)
				{
					MessageBox::Show("No accounts to save.", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				// Create a list of strings to write
				List<String^>^ lines = gcnew List<String^>();

				// Write each account to the list
				for each (customerAccounts ^ account in accounts)
				{
					// Format: AccountNo,CustomerName,Address,Suburb,PropertyType,PreviousUsage,CurrentUsage,RefuseBin
					String^ line = account->getAccountNo().ToString() + "," +
						account->getCustomerName() + "," +
						account->getAddress() + "," +
						account->getSuburb() + "," +
						account->getPropertyType() + "," +
						account->getPreviousUsage().ToString() + "," +
						account->getCurrentUsage().ToString() + "," +
						account->getRefuseBin();

					lines->Add(line);
				}

				// WriteAllLines automatically opens, writes, and closes the file
				System::IO::File::WriteAllLines(filename, lines);

				MessageBox::Show("Successfully saved " + accounts->Count + " accounts to " + filename,
					"Save Successful", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error saving file: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}
		private: System::Void lstDisplay_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
		}
		private: System::Void deleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				// Check if an item is selected in the listbox
				if (lstDisplay->SelectedIndex < 0)
				{
					MessageBox::Show("Please select an account to delete.",
						"No Selection", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				// Get the selected account from the accounts collection using the selected index
				int selectedIndex = lstDisplay->SelectedIndex;
				customerAccounts^ selectedAccount = accounts[selectedIndex];

				// Show confirmation dialog
				System::Windows::Forms::DialogResult result = MessageBox::Show(
					"Are you sure you want to delete account:\n\n" +
					"Account No: " + selectedAccount->getAccountNo() + "\n" +
					"Customer: " + selectedAccount->getCustomerName(),
					"Confirm Delete",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Warning
				);

				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					// Remove from accounts collection
					accounts->RemoveAt(selectedIndex);

					// Remove from listbox display
					lstDisplay->Items->RemoveAt(selectedIndex);

					// Clear input fields in case they were showing this account
					//txtAccountNo->Clear();
					//txtCustomerName->Clear();
					//txtAddress->Clear();
					//txtSuburb->Clear();
					//txtPropertyType->Clear();
					//txtPreviousUsage->Clear();
					//txtCurrentUsage->Clear();
					//txtRefuseBin->Clear();

					MessageBox::Show("Account deleted successfully!", "Success",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error deleting account: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void addToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			// Create an instance of AddEditForm
			AddEditForm^ addForm = gcnew AddEditForm();

			// Show the form as a dialog
			System::Windows::Forms::DialogResult result = addForm->ShowDialog();

			// Check if user clicked Save
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				try
				{
					// Get values from the form using its properties
					int accountNo = addForm->AccountNo;
					String^ customerName = addForm->CustomerName;
					String^ address = addForm->Address;
					String^ suburb = addForm->Suburb;
					String^ propertyType = addForm->PropertyType;
					int previousUsage = addForm->PreviousUsage;
					int currentUsage = addForm->CurrentUsage;
					String^ refuseBin = addForm->RefuseBin;

					// Create new customer account
					customerAccounts^ newAccount = gcnew customerAccounts(
						accountNo, customerName, address, suburb,
						propertyType, previousUsage, currentUsage, refuseBin
					);

					// Add to collection
					accounts->Add(newAccount);

					// Display in listbox
					//lstDisplay->Items->Add(newAccount->GetBillSummary());
					lstDisplay->Items->Add(newAccount->getAccountNo() + " --- " + newAccount->getCustomerName() + " --- " + newAccount->getAddress() + " --- "
						+ " --- " + newAccount->getSuburb() + " --- " + newAccount->getPropertyType() + " --- " +
						newAccount->getPreviousUsage() + " --- " + newAccount->getCurrentUsage() + " --- " + newAccount->getRefuseBin());



					MessageBox::Show("Customer added successfully!", "Success");
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Error: " + ex->Message);
				}

			}

		}

		private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e)
		{

		}

		private: System::Void updateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				// Check if an item is selected in the listbox
				if (lstDisplay->SelectedIndex < 0)
				{
					MessageBox::Show("Please select a customer to update.",
						"No Selection", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				// Get the selected customer
				int selectedIndex = lstDisplay->SelectedIndex;
				customerAccounts^ selectedCustomer = accounts[selectedIndex];

				// Create AddEditForm in Update mode, passing the selected customer
				AddEditForm^ updateForm = gcnew AddEditForm(selectedCustomer);

				// Show the form as a dialog
				System::Windows::Forms::DialogResult result = updateForm->ShowDialog();

				// Check if user clicked Save
				if (result == System::Windows::Forms::DialogResult::OK)
				{
					// Update the customer with new values from form
					selectedCustomer->setAccountNo(updateForm->AccountNo);
					selectedCustomer->setCustomersName(updateForm->CustomerName);
					selectedCustomer->setAddress(updateForm->Address);
					selectedCustomer->setSuburb(updateForm->Suburb);
					selectedCustomer->setPropertyType(updateForm->PropertyType);
					selectedCustomer->setPreviousUsage(updateForm->PreviousUsage);
					selectedCustomer->setCurrentUsage(updateForm->CurrentUsage);
					selectedCustomer->setRefuseBin(updateForm->RefuseBin);

					// Refresh the listbox display
					// Remove old item and add updated one
					lstDisplay->Items->RemoveAt(selectedIndex);
					lstDisplay->Items->Insert(selectedIndex, selectedCustomer->GetBillSummary());
					lstDisplay->SelectedIndex = selectedIndex;  // Keep it selected

					MessageBox::Show("Customer updated successfully!", "Success",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error updating customer: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void lstDisplay_DoubleClick(System::Object^ sender, System::EventArgs^ e) 
		{
			updateToolStripMenuItem_Click(sender, e);
		}

		private: System::Void accountNoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				if (accounts->Count == 0)
				{
					MessageBox::Show("No accounts to sort.", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				// Simple bubble sort for Account No
				for (int i = 0; i < accounts->Count - 1; i++)
				{
					for (int j = 0; j < accounts->Count - i - 1; j++)
					{
						if (accounts[j]->getAccountNo() > accounts[j + 1]->getAccountNo())
						{
							// Swap
							customerAccounts^ temp = accounts[j];
							accounts[j] = accounts[j + 1];
							accounts[j + 1] = temp;
						}
					}
				}

				// Refresh the display
				RefreshDisplay();

				MessageBox::Show("Accounts sorted by Account Number.", "Sort Complete",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error sorting by Account No: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: System::Void customerNameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try
			{
				if (accounts->Count == 0)
				{
					MessageBox::Show("No accounts to sort.", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				// Simple bubble sort for Customer Name
				for (int i = 0; i < accounts->Count - 1; i++)
				{
					for (int j = 0; j < accounts->Count - i - 1; j++)
					{
						// Compare strings using CompareTo
						if (accounts[j]->getCustomerName()->CompareTo(accounts[j + 1]->getCustomerName()) > 0)
						{
							// Swap
							customerAccounts^ temp = accounts[j];
							accounts[j] = accounts[j + 1];
							accounts[j + 1] = temp;
						}
					}
				}

				// Refresh the display
				RefreshDisplay();

				MessageBox::Show("Accounts sorted by Customer Name.", "Sort Complete",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error sorting by Customer Name: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}

	// Helper method to refresh the display after sorting
		private: void RefreshDisplay()
		{
			lstDisplay->Items->Clear();
			for each (customerAccounts ^ acc in accounts)
			{
				lstDisplay->Items->Add(acc->getAccountNo() + " --- " +
					acc->getCustomerName() + " --- " +
					acc->getAddress() + " --- " +
					acc->getSuburb() + " --- " +
					acc->getPropertyType() + " --- " +
					acc->getPreviousUsage() + " --- " +
					acc->getCurrentUsage() + " --- " +
					acc->getRefuseBin());
			}
		}
	private: System::Void searchToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			// Check if there are accounts to search
			if (accounts->Count == 0)
			{
				MessageBox::Show("No accounts to search. Please load or add accounts first.",
					"Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			// Create and show search form
			SearchCustomers^ searchForm = gcnew SearchCustomers(accounts);

			// Show as dialog (not returning anything, just displaying)
			searchForm->ShowDialog();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error opening search: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show(
		"Municipal Billing System\n\n" +
		"Version 1.0\n\n" +
		"A customer billing system for managing\n" +
		"water, waste, and sewerage charges.\n\n" +
		"© 2026",
		"About",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);
}
};
}



