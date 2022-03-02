#pragma once
#include "wx/wx.h"
#include "Grid.h"

class cMain : public wxFrame
{
public:
	cMain();
	//wxButton* button1;
	Grid new_grid;
	wxButton** sudoku_grid;
	void OnButtonClicked(wxCommandEvent &);
	void keyPressed(wxKeyEvent&);
	wxDECLARE_EVENT_TABLE();
	wxButton* selected_button;
	int remaining = 81;
};

