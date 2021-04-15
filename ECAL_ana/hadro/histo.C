{
  TCanvas *c1 = new TCanvas("c1","c1",900,600);
  
  TFile histo2("hadro_1t499.root");
  TFile histo4("hadro_500t999.root");
  TFile histo6("hadro_1000t1499.root");
  TFile histo8("hadro_1500t2000.root");

  TH1D *hGen_E2 = (TH1D*)histo2.Get("hGen_E");
  TH1D *E_N_Max2 = ((TH2D*)histo2.Get("h2_E_Theta_N_Max"))->ProjectionX("2N"); 
  TH1D *E_pi_Max2 = ((TH2D*)histo2.Get("h2_E_Theta_pi_Max"))->ProjectionX("2pi"); 
  TH1D *E_mu_Max2 = ((TH2D*)histo2.Get("h2_E_Theta_mu_Max"))->ProjectionX("2mu"); 
  
  TH1D *hGen_E4 = (TH1D*)histo4.Get("hGen_E");
  TH1D *E_N_Max4 = ((TH2D*)histo4.Get("h2_E_Theta_N_Max"))->ProjectionX("4N");
  TH1D *E_pi_Max4 = ((TH2D*)histo4.Get("h2_E_Theta_pi_Max"))->ProjectionX("4pi"); 
  TH1D *E_mu_Max4 = ((TH2D*)histo4.Get("h2_E_Theta_mu_Max"))->ProjectionX("4mu"); 
 
  TH1D *hGen_E6 = (TH1D*)histo6.Get("hGen_E");
  TH1D *E_N_Max6 = ((TH2D*)histo6.Get("h2_E_Theta_N_Max"))->ProjectionX("6N");
  TH1D *E_pi_Max6 = ((TH2D*)histo6.Get("h2_E_Theta_pi_Max"))->ProjectionX("6pi"); 
  TH1D *E_mu_Max6 = ((TH2D*)histo2.Get("h2_E_Theta_mu_Max"))->ProjectionX("6mu"); 
 
  TH1D *hGen_E8 = (TH1D*)histo8.Get("hGen_E");
  TH1D *E_N_Max8 = ((TH2D*)histo8.Get("h2_E_Theta_N_Max"))->ProjectionX("8N");
  TH1D *E_pi_Max8 = ((TH2D*)histo8.Get("h2_E_Theta_pi_Max"))->ProjectionX("8pi"); 
  TH1D *E_mu_Max8 = ((TH2D*)histo8.Get("h2_E_Theta_mu_Max"))->ProjectionX("8mu"); 
  

  double POT2 = (hGen_E2->GetEntries())/(hGen_E2->Integral());
  double POT4 = (hGen_E4->GetEntries())/(hGen_E4->Integral());
  double POT6 = (hGen_E6->GetEntries())/(hGen_E6->Integral());
  double POT8 = (hGen_E8->GetEntries())/(hGen_E8->Integral());

 
  E_N_Max2->Scale(1/POT2); 
  E_N_Max4->Scale(1/POT4);  
  E_N_Max6->Scale(1/POT6);
  E_N_Max8->Scale(1/POT8);

  E_pi_Max2->Scale(1/POT2); 
  E_pi_Max4->Scale(1/POT4);  
  E_pi_Max6->Scale(1/POT6);
  E_pi_Max8->Scale(1/POT8);

  E_mu_Max2->Scale(1/POT2); 
  E_mu_Max4->Scale(1/POT4);  
  E_mu_Max6->Scale(1/POT6);
  E_mu_Max8->Scale(1/POT8);


  //Neutroni

  double E2,E4,E6,E8;
  double I2 = E_N_Max2->IntegralAndError(140,1100,E2);
  double I4 = E_N_Max4->IntegralAndError(140,1100,E4);
  double I6 = E_N_Max6->IntegralAndError(140,1100,E6);
  double I8 = E_N_Max8->IntegralAndError(140,1100,E8);

  TGraphErrors gr1;
  gr1.SetPoint(0,2,I2*1E13);
  gr1.SetPoint(1,4,I4*1E13);
  gr1.SetPoint(2,6,I6*1E13);
  gr1.SetPoint(3,8,I8*1E13);

  gr1.SetPointError(0,0,E2*1E13);
  gr1.SetPointError(1,0,E4*1E13);
  gr1.SetPointError(2,0,E6*1E13);
  gr1.SetPointError(3,0,E8*1E13);
 

  gr1.SetMarkerStyle(20);
  gr1.SetTitle("10^{13} e^{+} OT");
  gr1.GetXaxis()->SetTitle("E cut (GeV)");
  gr1.GetYaxis()->SetTitle("expected N: Ek>500MeV");
  c1->SetLogy();
  //gr1.Draw("AP");
 
  TFile gr("gr.root","recreate");
  gr1.Write();

  //Pioni
  I2 = E_pi_Max2->IntegralAndError(2,1100,E2);
  I4 = E_pi_Max4->IntegralAndError(2,1100,E4);
  I6 = E_pi_Max6->IntegralAndError(2,1100,E6);
  I8 = E_pi_Max8->IntegralAndError(2,1100,E8);

  TGraphErrors gr2;
  gr2.SetPoint(0,2,I2*1E13);
  gr2.SetPoint(1,4,I4*1E13);
  gr2.SetPoint(2,6,I6*1E13);
  gr2.SetPoint(3,8,I8*1E13);

  gr2.SetPointError(0,0,E2*1E13);
  gr2.SetPointError(1,0,E4*1E13);
  gr2.SetPointError(2,0,E6*1E13);
  gr2.SetPointError(3,0,E8*1E13);
 

  gr2.SetMarkerStyle(20);
  gr2.SetTitle("10^{13} e^{+} OT");
  gr2.GetXaxis()->SetTitle("E cut (GeV)");
  gr2.GetYaxis()->SetTitle("expected #pi^{#pm}: Ek>100MeV");
  //gr2.Draw("AP");
 
  gr2.Write();

  //Muoni
  I2 = E_mu_Max2->IntegralAndError(2,1100,E2);
  I4 = E_mu_Max4->IntegralAndError(2,1100,E4);
  I6 = E_mu_Max6->IntegralAndError(2,1100,E6);
  I8 = E_mu_Max8->IntegralAndError(2,1100,E8);

  TGraphErrors gr3;
  gr3.SetPoint(0,2,I2*1E13);
  gr3.SetPoint(1,4,I4*1E13);
  gr3.SetPoint(2,6,I6*1E13);
  gr3.SetPoint(3,8,I8*1E13);

  gr3.SetPointError(0,0,E2*1E13);
  gr3.SetPointError(1,0,E4*1E13);
  gr3.SetPointError(2,0,E6*1E13);
  gr3.SetPointError(3,0,E8*1E13);
 

  gr3.SetMarkerStyle(20);
  gr3.SetTitle("10^{13} e^{+} OT");
  gr3.GetXaxis()->SetTitle("E cut (GeV)");
  gr3.GetYaxis()->SetTitle("expected #mu^{#pm}: Ek>100MeV");
  gr3.Draw("AP");
 
  gr3.Write();

}
