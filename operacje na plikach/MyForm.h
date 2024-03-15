#pragma once


namespace operacjenaplikach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace IO;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::TextBox^ tbInfo;
	private: System::Windows::Forms::Button^ btnSaveToFile;
	private: System::Windows::Forms::Button^ btnOpenFile;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->tbInfo = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveToFile = (gcnew System::Windows::Forms::Button());
			this->btnOpenFile = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnClose->Location = System::Drawing::Point(474, 414);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"zamknij";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MyForm::btnClose_Click);
			// 
			// tbInfo
			// 
			this->tbInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbInfo->Location = System::Drawing::Point(23, 30);
			this->tbInfo->Multiline = true;
			this->tbInfo->Name = L"tbInfo";
			this->tbInfo->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbInfo->Size = System::Drawing::Size(423, 386);
			this->tbInfo->TabIndex = 1;
			this->tbInfo->WordWrap = false;
			// 
			// btnSaveToFile
			// 
			this->btnSaveToFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnSaveToFile->Location = System::Drawing::Point(473, 338);
			this->btnSaveToFile->Name = L"btnSaveToFile";
			this->btnSaveToFile->Size = System::Drawing::Size(75, 23);
			this->btnSaveToFile->TabIndex = 2;
			this->btnSaveToFile->Text = L"Zapisz";
			this->btnSaveToFile->UseVisualStyleBackColor = true;
			this->btnSaveToFile->Click += gcnew System::EventHandler(this, &MyForm::btnSaveToFile_Click);
			// 
			// btnOpenFile
			// 
			this->btnOpenFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpenFile->Location = System::Drawing::Point(473, 376);
			this->btnOpenFile->Name = L"btnOpenFile";
			this->btnOpenFile->Size = System::Drawing::Size(75, 23);
			this->btnOpenFile->TabIndex = 3;
			this->btnOpenFile->Text = L"Otworz";
			this->btnOpenFile->UseVisualStyleBackColor = true;
			this->btnOpenFile->Click += gcnew System::EventHandler(this, &MyForm::btnOpenFile_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 462);
			this->Controls->Add(this->btnOpenFile);
			this->Controls->Add(this->btnSaveToFile);
			this->Controls->Add(this->tbInfo);
			this->Controls->Add(this->btnClose);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void btnSaveToFile_Click(System::Object^ sender, System::EventArgs^ e) {

		double A[10];
		for (int i = 0; i < 10; i++) {
			A[i] = 4 * i*i - 3 * i + 5;

		}
		tbInfo->AppendText("elementy tablicy\r\n");
		for (int i = 0; i < 10; i++){
			tbInfo->AppendText("A[" + i.ToString() + "]=" + A [i].ToString() + "\r\n");
		}

		SaveFileDialog^ okienkoDoZapisu = gcnew SaveFileDialog();

		okienkoDoZapisu->Filter = "Pliki tekstowe|*.txt|Wszystkie pliki|*.*";
		okienkoDoZapisu->Title = "Zapis tablicy do pliku";
		if (okienkoDoZapisu->ShowDialog() == Windows::Forms::DialogResult::OK) //warunek klikniecia zapis i zapisania albo anuluj/krzyzyk i nie zapisania
		{
			tbInfo->AppendText("Zapis do pliku\r\n");
			String^ nazwaPliku = okienkoDoZapisu->FileName;
			tbInfo->AppendText("Nazwa pliku " + nazwaPliku + "\r\n");
			StreamWriter^ strumienWyjsciowy = gcnew StreamWriter(nazwaPliku);
			for (int i = 0; i < 10; i++)
			{
				strumienWyjsciowy->WriteLine(A[i].ToString());
			}
			strumienWyjsciowy->Close();
			tbInfo->AppendText("zapisano do pliku\r\n");
		}
		else
		{
			tbInfo->AppendText("Anulowano zapis do pliku\r\n");
		}
	}
	private: System::Void btnOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ okienkoDoOtwarcia = gcnew OpenFileDialog();
		okienkoDoOtwarcia->Filter = "Pliki tekstowe|*.txt|Wszystkie pliki|*.*";
		okienkoDoOtwarcia->Title = "Wczytanie danych z pliku";
		

		double A[10];
		if (okienkoDoOtwarcia->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			tbInfo->AppendText("Wczytanie danych z pliku\r\n");
			String^ nazwaPliku = okienkoDoOtwarcia->FileName;
			tbInfo->AppendText("nazwa pliku: " + nazwaPliku + "\r\n");
			StreamReader^ strumienWejsciowy = gcnew StreamReader(nazwaPliku);
			for (int i = 0; i < 10; i++)
			{
				String^ wiersz = strumienWejsciowy->ReadLine();
				Double liczba = Convert::ToDouble(wiersz);
				A[i] = liczba; 
			}
			strumienWejsciowy->Close();
			
			for (int i = 0; i < 10; i++)
			{
				tbInfo->AppendText("A[" + i.ToString() + "]=" + A[i].ToString() + "\r\n");
			}
		}
		else
		{
			tbInfo->AppendText("Anulowano wczytanie pliku\r\n");
		}
	}
};
}
