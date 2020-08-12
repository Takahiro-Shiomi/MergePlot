#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "TLegend.h"
#include "/home/shiomi/RootUtils/AtlasUtils.C"

using namespace std;

void datasetText()
{
  //myText(0.2, 0.83, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4, 3-station coincidence w/ HotRoI Mask");
  //myText(0.2, 0.83, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4, 3-station coincidence");
  //myText(0.2, 0.83, 1, "Single #mu, 1.05<|#eta^{offline}|<2.4");
}
void datasetText1()
{
  //myText(0.2, 0.76, 1, "Only 3-station coincidence");
}

void Draw()
{

    TFile *file = new TFile("/gpfs/fs7001/shiomi/ATLAS/Physics/Bmumu/Data/TriggerLateStudyinRun2Data/run/rootfile/TriggerLateStudy_Bsmumu_0812_Run2Data_3sta_Match.root", "read");
    TH1D *h_mass_B;
    h_mass_B= (TH1D*)file->Get("h_mass");

    TFile *file1 = new TFile("/gpfs/fs7001/shiomi/ATLAS/Physics/Bmumu/Data/TriggerLateStudyinRun2Data/run/rootfile/TriggerLateStudy_JPsimumu_0812_Run2Data_3sta_Match.root", "read");
    TH1D *h_mass_Jpsi;
    h_mass_Jpsi= (TH1D*)file1->Get("h_mass");

    TFile *file2 = new TFile("/gpfs/fs7001/shiomi/ATLAS/Physics/Upsimumu/Data/TriggerLateStudyUpsimumu/run/rootfile/TriggerLateStudy_Upsimumu_0812_Run2Data_3sta_Match.root", "read");
    TH1D *h_mass_U;
    h_mass_U= (TH1D*)file2->Get("h_mass");

    TCanvas *c1 = new TCanvas("c1","c1",1200,800);
    h_mass_Jpsi->Draw();
    h_mass_Jpsi->SetLineColor(kRed+1);
    h_mass_Jpsi->SetFillColor(kRed+1);
    h_mass_Jpsi->SetFillStyle(3015);
    h_mass_B->Draw("same hist");
    h_mass_B->SetLineColor(kGreen+1);
    h_mass_B->SetFillColor(kGreen+1);
    h_mass_B->SetFillStyle(3015);
    h_mass_U->Draw("same hist");
    h_mass_U->SetLineColor(kBlue);
    h_mass_U->SetFillColor(kBlue);
    h_mass_U->SetFillStyle(3015);


    /*
    ATLASLabel(0.2,0.88,"Simulation Internal");
    datasetText();
    //datasetText1();
    TLegend* legend =new TLegend(0.75,0.70,1.0,0.18);
    legend->SetHeader("p_{T} Threshold");
    legend->AddEntry(pEff[0],"3 GeV","LP");
    legend->AddEntry(pEff[1],"4 GeV","LP");
    legend->SetBorderSize(0);
    legend->SetFillStyle(0);
    legend->Draw("same L");
    */

    c1->Print("./pdf/MassRoI_Bs_Jpsi_Upsi_Data_0812.png");
}

