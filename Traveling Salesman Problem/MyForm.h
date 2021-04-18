#pragma once
#include "Points.h"
#include "HeldKarp.h"

namespace TravelingSalesmanProblem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			
			InitializeComponent();
			Graficador = Canvas->CreateGraphics();
			cont = 0;
			points = new Points();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete Graficador;
		}
	private: 
		
		
		System::Windows::Forms::Panel^ Canvas;
		Graphics^ Graficador;
		int cont;
		Points* points;
		HeldKarp* answer;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ lbCoordenadas;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ btnCalcular;
	private: System::Windows::Forms::TextBox^ txtDistancia;

	private: System::Windows::Forms::Button^ btnLimpiar;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ lblDistancia;

	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::TextBox^ txtTiempo;
	private: System::Windows::Forms::Label^ lblIteaciones;
	private: System::Windows::Forms::TextBox^ txtIteraciones;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Canvas = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbCoordenadas = (gcnew System::Windows::Forms::ListBox());
			this->btnCalcular = (gcnew System::Windows::Forms::Button());
			this->txtDistancia = (gcnew System::Windows::Forms::TextBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->lblDistancia = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->txtTiempo = (gcnew System::Windows::Forms::TextBox());
			this->lblIteaciones = (gcnew System::Windows::Forms::Label());
			this->txtIteraciones = (gcnew System::Windows::Forms::TextBox());
			this->Canvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// Canvas
			// 
			this->Canvas->BackColor = System::Drawing::Color::Silver;
			this->Canvas->Controls->Add(this->label13);
			this->Canvas->Controls->Add(this->label12);
			this->Canvas->Controls->Add(this->label11);
			this->Canvas->Controls->Add(this->label10);
			this->Canvas->Controls->Add(this->label9);
			this->Canvas->Controls->Add(this->label7);
			this->Canvas->Controls->Add(this->label5);
			this->Canvas->Controls->Add(this->label4);
			this->Canvas->Controls->Add(this->label3);
			this->Canvas->Controls->Add(this->label1);
			this->Canvas->Controls->Add(this->label8);
			this->Canvas->Controls->Add(this->label6);
			this->Canvas->Controls->Add(this->label2);
			this->Canvas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->Canvas->Location = System::Drawing::Point(151, 12);
			this->Canvas->Margin = System::Windows::Forms::Padding(2);
			this->Canvas->Name = L"Canvas";
			this->Canvas->Size = System::Drawing::Size(680, 660);
			this->Canvas->TabIndex = 0;
			this->Canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Canvas_Paint);
			this->Canvas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Canvas_MouseClick);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(650, 630);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(24, 17);
			this->label13->TabIndex = 18;
			this->label13->Text = L"30";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(550, 630);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(24, 17);
			this->label12->TabIndex = 17;
			this->label12->Text = L"25";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(450, 630);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(24, 17);
			this->label11->TabIndex = 16;
			this->label11->Text = L"20";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(350, 630);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(24, 17);
			this->label10->TabIndex = 15;
			this->label10->Text = L"15";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(250, 630);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 17);
			this->label9->TabIndex = 14;
			this->label9->Text = L"10";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(150, 630);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 17);
			this->label7->TabIndex = 13;
			this->label7->Text = L"5";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(37, 620);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(37, 515);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"5";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(28, 415);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"10";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 315);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"15";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(28, 215);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 17);
			this->label8->TabIndex = 8;
			this->label8->Text = L"20";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(28, 115);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 17);
			this->label6->TabIndex = 6;
			this->label6->Text = L"25";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(28, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"30";
			// 
			// lbCoordenadas
			// 
			this->lbCoordenadas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCoordenadas->FormattingEnabled = true;
			this->lbCoordenadas->ItemHeight = 17;
			this->lbCoordenadas->Location = System::Drawing::Point(12, 12);
			this->lbCoordenadas->Name = L"lbCoordenadas";
			this->lbCoordenadas->Size = System::Drawing::Size(134, 259);
			this->lbCoordenadas->TabIndex = 1;
			// 
			// btnCalcular
			// 
			this->btnCalcular->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Lime;
			this->btnCalcular->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->btnCalcular->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCalcular->Font = (gcnew System::Drawing::Font(L"Verdana", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCalcular->Location = System::Drawing::Point(13, 286);
			this->btnCalcular->Name = L"btnCalcular";
			this->btnCalcular->Size = System::Drawing::Size(134, 38);
			this->btnCalcular->TabIndex = 2;
			this->btnCalcular->Text = L"Calcular";
			this->btnCalcular->UseVisualStyleBackColor = true;
			this->btnCalcular->Click += gcnew System::EventHandler(this, &MyForm::btnCalcular_Click);
			// 
			// txtDistancia
			// 
			this->txtDistancia->Font = (gcnew System::Drawing::Font(L"Verdana", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDistancia->ForeColor = System::Drawing::Color::DarkGray;
			this->txtDistancia->Location = System::Drawing::Point(14, 363);
			this->txtDistancia->MaxLength = 10;
			this->txtDistancia->Name = L"txtDistancia";
			this->txtDistancia->ReadOnly = true;
			this->txtDistancia->Size = System::Drawing::Size(133, 25);
			this->txtDistancia->TabIndex = 3;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->btnLimpiar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->btnLimpiar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Verdana", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->Location = System::Drawing::Point(13, 634);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(134, 38);
			this->btnLimpiar->TabIndex = 4;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = true;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &MyForm::btnLimpiar_Click);
			// 
			// lblDistancia
			// 
			this->lblDistancia->AutoSize = true;
			this->lblDistancia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDistancia->Location = System::Drawing::Point(12, 336);
			this->lblDistancia->Name = L"lblDistancia";
			this->lblDistancia->Size = System::Drawing::Size(69, 18);
			this->lblDistancia->TabIndex = 5;
			this->lblDistancia->Text = L"Distancia";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(11, 400);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(82, 18);
			this->lblTiempo->TabIndex = 7;
			this->lblTiempo->Text = L"Tiempo (S)";
			// 
			// txtTiempo
			// 
			this->txtTiempo->Font = (gcnew System::Drawing::Font(L"Verdana", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTiempo->ForeColor = System::Drawing::Color::DarkGray;
			this->txtTiempo->Location = System::Drawing::Point(13, 427);
			this->txtTiempo->MaxLength = 10;
			this->txtTiempo->Name = L"txtTiempo";
			this->txtTiempo->ReadOnly = true;
			this->txtTiempo->Size = System::Drawing::Size(133, 25);
			this->txtTiempo->TabIndex = 6;
			// 
			// lblIteaciones
			// 
			this->lblIteaciones->AutoSize = true;
			this->lblIteaciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIteaciones->Location = System::Drawing::Point(12, 467);
			this->lblIteaciones->Name = L"lblIteaciones";
			this->lblIteaciones->Size = System::Drawing::Size(80, 18);
			this->lblIteaciones->TabIndex = 9;
			this->lblIteaciones->Text = L"Iteraciones";
			// 
			// txtIteraciones
			// 
			this->txtIteraciones->Font = (gcnew System::Drawing::Font(L"Verdana", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIteraciones->ForeColor = System::Drawing::Color::DarkGray;
			this->txtIteraciones->Location = System::Drawing::Point(14, 494);
			this->txtIteraciones->MaxLength = 10;
			this->txtIteraciones->Name = L"txtIteraciones";
			this->txtIteraciones->ReadOnly = true;
			this->txtIteraciones->Size = System::Drawing::Size(133, 25);
			this->txtIteraciones->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(5, 9);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 693);
			this->Controls->Add(this->lblIteaciones);
			this->Controls->Add(this->txtIteraciones);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->txtTiempo);
			this->Controls->Add(this->lblDistancia);
			this->Controls->Add(this->btnLimpiar);
			this->Controls->Add(this->txtDistancia);
			this->Controls->Add(this->btnCalcular);
			this->Controls->Add(this->lbCoordenadas);
			this->Controls->Add(this->Canvas);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Traveling Salesman Problem";
			this->Canvas->ResumeLayout(false);
			this->Canvas->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		drawBase();
	}
	
	private: System::Void Canvas_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// min 20
		if (cont >= 15) {
			MessageBox::Show("Solo se permite como maximo 15 puntos");
			return;
		}
		// limites 
		if (e->X < 50 || e->X > 661 || e->Y < 22 || e->Y > 640) {
			return;
		}

		// dibujo
		int x = (e->X - ((e->X - 5) % 20)) + 5;
		int y = (e->Y - ((e->Y - 5) % 20)) - 10;

		// puntos
		int xp = (x - 40) / 20;
		int yp = 30 - (y / 20);

		//verifica que el punto no este repetido
		if (!points->addPoints(xp, yp)) return;

		if(cont == 0)
			Graficador->FillEllipse(Brushes::Blue, x , y, 15, 15);
		else
			Graficador->FillEllipse(Brushes::Black, x, y, 15, 15);

		//coloca las coordenadas en el graficador
		Graficador->DrawString(gcnew String("(" + xp.ToString() + "," + yp.ToString() + ")"), gcnew System::Drawing::Font("Microsoft Sans Serif", 11.25F), gcnew SolidBrush(Color::Black), x + 17, y);
		
		lbCoordenadas->Items->Clear();
		for (int i = 0; i < points->getnodes().size(); i++) {
			lbCoordenadas->Items->Add("{ " + Convert::ToString(points->getnodes()[i].first) + " , " 
				+ Convert::ToString(points->getnodes()[i].second) + " }");
		}
		cont++;
	}
	
	private: System::Void btnCalcular_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cont < 2) {
			MessageBox::Show("Debe haber minimo 2 puntos");
			return;
		}
		clearCanvas();
		answer = new HeldKarp(cont, 0, points->getnodes());
		Decimal respuesta;
		txtDistancia->Text = Convert::ToString(respuesta.Round(Convert::ToDecimal(answer->getMinimunDistance()),3));
		txtTiempo->Text = Convert::ToString(respuesta.Round(Convert::ToDecimal(answer->getExecutionTime()), 3));
		txtIteraciones->Text = Convert::ToString(respuesta.Round(Convert::ToDecimal(answer->getCantIterations()), 0));
		drawLines(answer->getRoute());
	}

	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		points->cleaner();
		answer->~HeldKarp();
		lbCoordenadas->Items->Clear();
		txtDistancia->Text = "";
		txtTiempo->Text = "";
		txtIteraciones->Text = "";
		clearCanvas();
		cont = 0;
	}

	void drawBase() {
		Graficador->FillRectangle(Brushes::Red, 55, 620, 610, 5);
		Graficador->FillRectangle(Brushes::Red, 55, 15, 5, 610);
	}

	void clearCanvas() {
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(Graficador, this->ClientRectangle);
		buffer->Graphics->Clear(Color::Silver);
		buffer->Render(Graficador);
		delete buffer, espacio;

		Canvas->BackColor = Color::Silver;
		drawBase();
	}

	void drawLines(vector<int> ans) {
		for (int i = 0; i < ans.size() - 1; i++) {

			int x = points->getnodes()[ans[i]].first; //coordenada x
			int y = points->getnodes()[ans[i]].second; //coordenada y

			int xp = x * 20 + 50; //coordenada x en el graficador
			int yp = 615 - y * 20; //coordenada y en el graficador

			//lineas
			Graficador->DrawLine(Pens::Green, xp + 7, yp + 7, points->getnodes()[ans[i + 1]].first * 20 + 57, 623 - points->getnodes()[ans[i + 1]].second * 20);	

			//circulos encima
			if (i == 0) {
				Graficador->FillEllipse(Brushes::Blue, xp, yp, 15, 15);
			}
			else {
				Graficador->FillEllipse(Brushes::Black, xp, yp, 15, 15);
			}

			Graficador->DrawString(gcnew String("(" + x.ToString() + "," + y.ToString() + ")"), gcnew System::Drawing::Font("Microsoft Sans Serif", 11.25F), gcnew SolidBrush(Color::Black), xp + 17, yp);
		}

	}
};
}
