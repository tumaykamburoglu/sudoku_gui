#include "cMain.h"
#include "wx/wx.h"
#include "Grid.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_CHAR_HOOK(keyPressed)
wxEND_EVENT_TABLE()

cMain::cMain() :wxFrame(nullptr,wxID_ANY,"Sudoku",wxDefaultPosition,wxSize(600,600)) {
	//button1 = new wxButton(this, 10021, "Print", wxPoint(10, 10), wxSize(100, 500));
	sudoku_grid = new wxButton*[81];
	new_grid.hide(4);
	wxGridSizer* s_grid = new wxGridSizer(3, 3, 2, 2);
	wxGridSizer* s_grid1 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid2 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid3 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid4 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid5 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid6 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid7 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid8 = new wxGridSizer(3, 3, 0, 0);
	wxGridSizer* s_grid9 = new wxGridSizer(3, 3, 0, 0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudoku_grid[i * 9 + j] = new wxButton(this, 1000 + (i * 9 + j));
			if (new_grid.properity[i][j] == 1) {
				sudoku_grid[i * 9 + j]->DontShowLabel();
			}
			else {
				sudoku_grid[i * 9 + j]->SetLabel(std::to_string(new_grid.numbers[i][j]));
				remaining--;
				sudoku_grid[i * 9 + j]->Disable();
			}
			if ((j / 3) < 1) {
				if ((i / 3) < 1) {
					s_grid1->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
				else if ((i / 3) < 2) {
					s_grid4->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
				else {
					s_grid7->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
			}
			else if ((j / 3) < 2) {
				if ((i / 3) < 1) {
					s_grid2->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
				else if ((i / 3) < 2) {
					s_grid5->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
				else {
					s_grid8->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
			}
			else {
				if ((i / 3) < 1) {
					s_grid3->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
				else if ((i / 3) < 2) {
					s_grid6->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
				else {
					s_grid9->Add(sudoku_grid[i * 9 + j], 1, wxEXPAND | wxALL);
				}
			}
			Bind(wxEVT_BUTTON, &cMain::OnButtonClicked, this, 1000 + (i * 9 + j));
		}
		
	}
	s_grid->Add(s_grid1, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid2, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid3, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid4, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid5, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid6, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid7, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid8, 1, wxEXPAND | wxALL);
	s_grid->Add(s_grid9, 1, wxEXPAND | wxALL);
	this->SetSizer(s_grid);
	s_grid->Layout();	
}

void cMain::OnButtonClicked(wxCommandEvent& evnt) {

	selected_button = wxDynamicCast(evnt.GetEventObject(),wxButton);
	evnt.Skip();
}

void cMain::keyPressed(wxKeyEvent& evnt) {
	int n = evnt.GetKeyCode()-48;
	if (n > 0 && n < 10) {
		int index = selected_button->GetId() - 1000;
		int row = index / 9;
		int column = index % 9;
		if (new_grid.numbers[row][column] == n) {
			selected_button->SetLabel(std::to_string(n));
			remaining--;
		}
		else {
			wxMessageBox(wxT("Game Over!"));
			wxExit();
		}
	}
	if (remaining == 0) {
		wxMessageBox(wxT("You Won!"));
		wxExit();
	}
	evnt.Skip();
}