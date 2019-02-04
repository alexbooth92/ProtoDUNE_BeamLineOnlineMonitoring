#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <TH1D.h>
#include <TCanvas.h>

int main(int argc, char *argv[])
{
  std::string s_InputFile = argv[1];
  std::string s_OutFile   = argv[2];

  TFile *f_In = new TFile((TString)s_InputFile,"UPDATE");
  TTree *t = (TTree*)f_In->Get("DumpBL_XBTF_Unique");

  TString *US_DetName = 0;
  TString *DS_DetName = 0;
  double TF;

  std::map<std::pair<TString,TString>,TH1D*> map_ChannelToHist;
  std::map<std::pair<TString,TString>,TH1D*> map_ChannelToHist_ROI;
  TH1D *h_AA     = new TH1D("h_AA",    "XBTF022687A to XBTF022716A", 301, -0.5,       300.5);
  TH1D *h_AA_ROI = new TH1D("h_AA_ROI","XBTF022687A to XBTF022716A", 900,  130, 130+900*0.1);
  TH1D *h_AB     = new TH1D("h_AB",    "XBTF022687A to XBTF022716B", 301, -0.5,       300.5);
  TH1D *h_AB_ROI = new TH1D("h_AB_ROI","XBTF022687A to XBTF022716B", 900,  130, 130+900*0.1);
  TH1D *h_BA     = new TH1D("h_BA",    "XBTF022687B to XBTF022716A", 301, -0.5,       300.5);
  TH1D *h_BA_ROI = new TH1D("h_BA_ROI","XBTF022687B to XBTF022716A", 900,  130, 130+900*0.1);
  TH1D *h_BB     = new TH1D("h_BB",    "XBTF022687B to XBTF022716B", 301, -0.5,       300.5);
  TH1D *h_BB_ROI = new TH1D("h_BB_ROI","XBTF022687B to XBTF022716B", 900,  130, 130+900*0.1);

  map_ChannelToHist[{"XBTF022687A","XBTF022716A"}] = h_AA;
  map_ChannelToHist[{"XBTF022687A","XBTF022716B"}] = h_AB;
  map_ChannelToHist[{"XBTF022687B","XBTF022716A"}] = h_BA;
  map_ChannelToHist[{"XBTF022687B","XBTF022716B"}] = h_BB;

  map_ChannelToHist_ROI[{"XBTF022687A","XBTF022716A"}] = h_AA_ROI;
  map_ChannelToHist_ROI[{"XBTF022687A","XBTF022716B"}] = h_AB_ROI;
  map_ChannelToHist_ROI[{"XBTF022687B","XBTF022716A"}] = h_BA_ROI;
  map_ChannelToHist_ROI[{"XBTF022687B","XBTF022716B"}] = h_BB_ROI;

  t->SetBranchAddress("US_DetName", &US_DetName);
  t->SetBranchAddress("DS_DetName", &DS_DetName);
  t->SetBranchAddress("TF", &TF);

  for(unsigned long i = 0; i < t->GetEntries(); i++)
  {
    t->GetEntry(i);
    map_ChannelToHist[{*US_DetName,*DS_DetName}]->Fill(TF);
    map_ChannelToHist_ROI[{*US_DetName,*DS_DetName}]->Fill(TF);
  }

  TFile *f_Out = new TFile((TString)s_OutFile,"UPDATE");
  TDirectory *dir = (TDirectory*)f_Out->Get("TF");
  dir->cd();
  for(auto hist : map_ChannelToHist)
  {
    hist.second->GetXaxis()->SetTitle("Time of Flight, (ns)");
    hist.second->GetYaxis()->SetTitle("Events");
    hist.second->GetYaxis()->SetTitleOffset(1.4);
    hist.second->Write();
  }
  for(auto hist : map_ChannelToHist_ROI)
  {
    hist.second->GetXaxis()->SetTitle("Time of Flight, (ns)");
    hist.second->GetYaxis()->SetTitle("Events");
    hist.second->GetYaxis()->SetTitleOffset(1.4);
    hist.second->Write();

    TString s_Title = (TString)hist.second->GetName()+"_Coarse";
    TH1D *h_Rebinned = (TH1D*)hist.second->Clone(s_Title);
    h_Rebinned->Rebin(3);
    h_Rebinned->Write();
    /*
    TCanvas *c = new TCanvas("c", "c", 800, 500);
    h_Rebinned->Draw();
    c->SaveAs((TString)h_Rebinned->GetName()+"_"+(TString)s_OutFileAppend+".pdf");*/
  }
  f_Out->Close();

  return 0;
}
