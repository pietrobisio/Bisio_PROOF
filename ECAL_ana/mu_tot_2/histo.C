{
  TCanvas *c1 = new TCanvas("c1","c1",900,600);
  
  TFile histo2("mu_tot_2_1t399.root");
  TFile histo3("mu_tot_2_1000t1299.root");
  TFile histo4("mu_tot_2_1300t1599.root");
  TFile histo5("mu_tot_2_1600t2000.root");
  TFile histo6("mu_tot_2_400t699.root");
  TFile histo7("mu_tot_2_700t999.root");

  TH1D *hGen_E2 = (TH1D*)histo2.Get("hGen_E");
  TH1D *E_mu_Max2 = ((TH2D*)histo2.Get("h2_E_Theta_mu_Max"))->ProjectionX("2"); 
  //TH1D *h_E_mu_Max_Exit12_2 = (TH1D*)histo2.Get("h2_E_Theta_mu_Max_Exit12")->ProjectionX("2A");
  //TH1D *h_E_mu_Max_Exit34_2 = (TH1D*)histo2.Get("h2_E_Theta_mu_Max_Exit24")->ProjectionX("2B");
  //TH1D *h_E_mu_Max_Exit56_2 = (TH1D*)histo2.Get("h2_E_Theta_mu_Max_Exit56")->ProjectionX("2C");
 
  TH1D *hGen_E3 = (TH1D*)histo3.Get("hGen_E");
  TH1D *E_mu_Max3 = ((TH2D*)histo3.Get("h2_E_Theta_mu_Max"))->ProjectionX("3");  
  TH1D *h_E_mu_Max_Exit12_3 = ((TH2D*)histo3.Get("h2_E_Theta_mu_Max_Exit12"))->ProjectionX("3A");
  TH1D *h_E_mu_Max_Exit34_3 = ((TH2D*)histo3.Get("h2_E_Theta_mu_Max_Exit34"))->ProjectionX("3B");
  TH1D *h_E_mu_Max_Exit56_3 = ((TH2D*)histo3.Get("h2_E_Theta_mu_Max_Exit56"))->ProjectionX("3C");
  
  TH1D *hGen_E4 = (TH1D*)histo4.Get("hGen_E");
  TH1D *E_mu_Max4 = ((TH2D*)histo4.Get("h2_E_Theta_mu_Max"))->ProjectionX("4");
  TH1D *h_E_mu_Max_Exit12_4 = ((TH2D*)histo4.Get("h2_E_Theta_mu_Max_Exit12"))->ProjectionX("4A");
  TH1D *h_E_mu_Max_Exit34_4 = ((TH2D*)histo4.Get("h2_E_Theta_mu_Max_Exit34"))->ProjectionX("4B");
  TH1D *h_E_mu_Max_Exit56_4 = ((TH2D*)histo4.Get("h2_E_Theta_mu_Max_Exit56"))->ProjectionX("4C");
  
  TH1D *hGen_E5 = (TH1D*)histo5.Get("hGen_E");
  TH1D *E_mu_Max5 = ((TH2D*)histo5.Get("h2_E_Theta_mu_Max"))->ProjectionX("5");
  TH1D *h_E_mu_Max_Exit12_5 = ((TH2D*)histo5.Get("h2_E_Theta_mu_Max_Exit12"))->ProjectionX("5A");
  TH1D *h_E_mu_Max_Exit34_5 = ((TH2D*)histo5.Get("h2_E_Theta_mu_Max_Exit34"))->ProjectionX("5B");
  TH1D *h_E_mu_Max_Exit56_5 = ((TH2D*)histo5.Get("h2_E_Theta_mu_Max_Exit56"))->ProjectionX("5C");
  
  TH1D *hGen_E6 = (TH1D*)histo6.Get("hGen_E");
  TH1D *E_mu_Max6 = ((TH2D*)histo6.Get("h2_E_Theta_mu_Max"))->ProjectionX("6");
  TH1D *h_E_mu_Max_Exit12_6 = ((TH2D*)histo6.Get("h2_E_Theta_mu_Max_Exit12"))->ProjectionX("6A");
  TH1D *h_E_mu_Max_Exit34_6 = ((TH2D*)histo6.Get("h2_E_Theta_mu_Max_Exit34"))->ProjectionX("6B");
  TH1D *h_E_mu_Max_Exit56_6 = ((TH2D*)histo6.Get("h2_E_Theta_mu_Max_Exit56"))->ProjectionX("6C");

  TH1D *hGen_E7 = (TH1D*)histo7.Get("hGen_E");
  TH1D *E_mu_Max7 = ((TH2D*)histo7.Get("h2_E_Theta_mu_Max"))->ProjectionX("7");
  TH1D *h_E_mu_Max_Exit12_7 = ((TH2D*)histo7.Get("h2_E_Theta_mu_Max_Exit12"))->ProjectionX("7A");
  TH1D *h_E_mu_Max_Exit34_7 = ((TH2D*)histo7.Get("h2_E_Theta_mu_Max_Exit34"))->ProjectionX("7B");
  TH1D *h_E_mu_Max_Exit56_7 = ((TH2D*)histo7.Get("h2_E_Theta_mu_Max_Exit56"))->ProjectionX("7C");
 
  double bias = 1E4;

  double POT2 = (hGen_E2->GetEntries())/(hGen_E2->Integral());
  double POT3 = (hGen_E3->GetEntries())/(hGen_E3->Integral());
  double POT4 = (hGen_E4->GetEntries())/(hGen_E4->Integral());
  double POT5 = (hGen_E5->GetEntries())/(hGen_E5->Integral());
  double POT6 = (hGen_E6->GetEntries())/(hGen_E6->Integral());
  double POT7 = (hGen_E7->GetEntries())/(hGen_E7->Integral());

 
  E_mu_Max2->Scale(1/bias/POT2);
  //h_E_mu_Max_Exit12_2->Scale(1/bias/POT2);
  //h_E_mu_Max_Exit34_2->Scale(1/bias/POT2);
  //h_E_mu_Max_Exit56_2->Scale(1/bias/POT2);
  E_mu_Max3->Scale(1/bias/POT3);
  h_E_mu_Max_Exit12_3->Scale(1/bias/POT3);
  h_E_mu_Max_Exit34_3->Scale(1/bias/POT3);
  h_E_mu_Max_Exit56_3->Scale(1/bias/POT3);
  E_mu_Max4->Scale(1/bias/POT4);
  h_E_mu_Max_Exit12_4->Scale(1/bias/POT4);
  h_E_mu_Max_Exit34_4->Scale(1/bias/POT4);
  h_E_mu_Max_Exit56_4->Scale(1/bias/POT4);
  E_mu_Max5->Scale(1/bias/POT5);
  h_E_mu_Max_Exit12_5->Scale(1/bias/POT5);
  h_E_mu_Max_Exit34_5->Scale(1/bias/POT5);
  h_E_mu_Max_Exit56_5->Scale(1/bias/POT5);
  E_mu_Max6->Scale(1/bias/POT6);
  h_E_mu_Max_Exit12_6->Scale(1/bias/POT6);
  h_E_mu_Max_Exit34_6->Scale(1/bias/POT6);
  h_E_mu_Max_Exit56_6->Scale(1/bias/POT6);
  E_mu_Max7->Scale(1/bias/POT7);
  h_E_mu_Max_Exit12_7->Scale(1/bias/POT7);
  h_E_mu_Max_Exit34_7->Scale(1/bias/POT7);
  h_E_mu_Max_Exit56_7->Scale(1/bias/POT7);


  double E2,E3,E4,E5,E6,E7;
  double I2 = E_mu_Max2->IntegralAndError(0,1100,E2);
  double I3 = E_mu_Max3->IntegralAndError(0,1100,E3);
  double I4 = E_mu_Max4->IntegralAndError(0,1100,E4);
  double I5 = E_mu_Max5->IntegralAndError(0,1100,E5);
  double I6 = E_mu_Max6->IntegralAndError(0,1100,E6);
  double I7 = E_mu_Max7->IntegralAndError(0,1100,E7);

  TGraphErrors gr1;
  gr1.SetPoint(0,2,I2*1E13);
  gr1.SetPoint(1,3,I3*1E13);
  gr1.SetPoint(2,4,I4*1E13);
  gr1.SetPoint(3,5,I5*1E13);
  gr1.SetPoint(4,6,I6*1E13);
  gr1.SetPoint(5,7,I7*1E13);

  gr1.SetPointError(0,0,E2*1E13);
  gr1.SetPointError(1,0,E3*1E13);
  gr1.SetPointError(2,0,E4*1E13);
  gr1.SetPointError(3,0,E5*1E13);
  gr1.SetPointError(4,0,E6*1E13);
  gr1.SetPointError(5,0,E7*1E13);
  
  //gr1.SetMarkerStyle(20);
  gr1.SetTitle("10^{13} e^{+} OT");
  gr1.GetXaxis()->SetTitle("E cut (GeV)");
  gr1.GetYaxis()->SetTitle("expected #mu");
  gr1.Draw("AP");
 
  TFile gr("gr.root","recreate");
  gr1.Write();


  //Most energetic exiting muons spectum
 
  E_mu_Max2->SetTitle("E miss>2GeV");
  E_mu_Max2->GetXaxis()->SetTitle("E (MeV)");
  E_mu_Max2->GetYaxis()->SetTitle("#mu / (10MeV x POT)");
  E_mu_Max2->Write();
  // h_E_mu_Max_Exit12_2->SetLineColor(kRed);
  //h_E_mu_Max_Exit34_2->SetLineColor(kViolet);
  //h_E_mu_Max_Exit56_2->SetLineColor(kGreen);
  //h_E_mu_Max_Exit12_2 ->Draw("SAME");
  //h_E_mu_Max_Exit34_2 ->Draw("SAME");
  //h_E_mu_Max_Exit56_2 ->Draw("SAME");
  
 
  //legend->Draw();
  //c1->SaveAs("./PDF/2GeV.pdf");

  E_mu_Max3->SetTitle("E miss>3GeV");
  E_mu_Max3->GetXaxis()->SetTitle("E (MeV)");
  E_mu_Max3->GetYaxis()->SetTitle("#mu / (10MeV x POT)");
  E_mu_Max3->Write();
  E_mu_Max3->Draw();
  h_E_mu_Max_Exit12_3->SetLineColor(kRed);
  h_E_mu_Max_Exit34_3->SetLineColor(kViolet);
  h_E_mu_Max_Exit56_3->SetLineColor(kGreen);
  h_E_mu_Max_Exit12_3 ->Draw("SAME");
  h_E_mu_Max_Exit34_3 ->Draw("SAME");
  h_E_mu_Max_Exit56_3 ->Draw("SAME");
  TLegend *legend = new TLegend(0.7,0.5,0.9,0.7);
  legend->AddEntry("3","total distribution","l");
  legend->AddEntry("3A","1 or 2 exiting #mu","l");
  legend->AddEntry("3B","3 or 4 exiting #mu","l");
  legend->AddEntry("3C","5 or 6 exiting #mu","l"); 
  legend->Draw();    
  c1->SaveAs("./PDF/3GeV.pdf");

  E_mu_Max4->SetTitle("E miss>4GeV");
  E_mu_Max4->GetXaxis()->SetTitle("E (MeV)");
  E_mu_Max4->GetYaxis()->SetTitle("#mu / (10MeV x POT)");
  E_mu_Max4->Write();
  E_mu_Max4->Draw();
  h_E_mu_Max_Exit12_4->SetLineColor(kRed);
  h_E_mu_Max_Exit34_4->SetLineColor(kViolet);
  h_E_mu_Max_Exit56_4->SetLineColor(kGreen);
  h_E_mu_Max_Exit12_4 ->Draw("SAME");
  h_E_mu_Max_Exit34_4 ->Draw("SAME");
  h_E_mu_Max_Exit56_4 ->Draw("SAME");
  legend->Draw();
  c1->SaveAs("./PDF/4GeV.pdf");
  
  E_mu_Max5->SetTitle("E miss>5GeV");
  E_mu_Max5->GetXaxis()->SetTitle("E (MeV)");
  E_mu_Max5->GetYaxis()->SetTitle("#mu / (10MeV x POT)");
  E_mu_Max5->Write();
  E_mu_Max5->Draw();
  h_E_mu_Max_Exit12_5->SetLineColor(kRed);
  h_E_mu_Max_Exit34_5->SetLineColor(kViolet);
  h_E_mu_Max_Exit56_5->SetLineColor(kGreen);
  h_E_mu_Max_Exit12_5 ->Draw("SAME");
  h_E_mu_Max_Exit34_5 ->Draw("SAME");
  h_E_mu_Max_Exit56_5 ->Draw("SAME");
  legend->Draw();
  c1->SaveAs("./PDF/5GeV.pdf");
  
  E_mu_Max6->SetTitle("E miss>6GeV");
  E_mu_Max6->GetXaxis()->SetTitle("E (MeV)");
  E_mu_Max6->GetYaxis()->SetTitle("#mu / (10MeV x POT)");
  E_mu_Max6->Write();
  E_mu_Max6->Draw();
  h_E_mu_Max_Exit12_6->SetLineColor(kRed);
  h_E_mu_Max_Exit34_6->SetLineColor(kViolet);
  h_E_mu_Max_Exit56_6->SetLineColor(kGreen);
  h_E_mu_Max_Exit12_6 ->Draw("SAME");
  h_E_mu_Max_Exit34_6 ->Draw("SAME");
  h_E_mu_Max_Exit56_6 ->Draw("SAME");
  legend->Draw();
  c1->SaveAs("./PDF/6GeV.pdf");
  
  E_mu_Max7->SetTitle("E miss>7GeV");
  E_mu_Max7->GetXaxis()->SetTitle("E (MeV)");
  E_mu_Max7->GetYaxis()->SetTitle("#mu / (10MeV x POT)");
  E_mu_Max7->Write();
  E_mu_Max7->Draw();
  h_E_mu_Max_Exit12_7->SetLineColor(kRed);
  h_E_mu_Max_Exit34_7->SetLineColor(kViolet);
  h_E_mu_Max_Exit56_7->SetLineColor(kGreen);
  h_E_mu_Max_Exit12_7 ->Draw("SAME");
  h_E_mu_Max_Exit34_7 ->Draw("SAME");
  h_E_mu_Max_Exit56_7 ->Draw("SAME");
  legend->Draw();
  c1->SaveAs("./PDF/7GeV.pdf");
  
}
