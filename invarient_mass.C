void invarient_mass()
{
auto f=new TFile("target.root");
auto t=(TTree*)f->Get("T");
auto ht=new TH1F("ptt","pt of e",100,0,250);
int en=t->GetEntries();
std::vector<float> *pt=0;
std::vector<float> *phi=0;
std::vector<float> *eta=0;
std::vector<float> *e=0;
int a;
t->SetBranchAddress("Ele_Gen_Pt", &pt);
t->SetBranchAddress("Ele_Gen_Eta", &eta);
t->SetBranchAddress("Ele_Gen_Phi", &phi);
t->SetBranchAddress("Ele_Gen_E", &e);
t->SetBranchAddress("nElectrons",&a);
auto ht1=new TH1F("ptt1","no of e",100,-5,5);
auto ht2=new TH1F("ptt3","eta",100,-10,10);
auto ht3=new TH1F("ptt2","phi of e",100,-5,5.0);
auto ht4=new TH1F("ptt4","energy of e",100,0,5000);
auto ht5=new TH1F("ptt5","dimass ",100,0,150);
TF1 g("gs","gaus",80,100);
float aa,a1,a2,a3,a4;

TLorentzVector l1,l2,l;
for (int i=0;i<en;i++){
t->GetEntry(i);
ht1->Fill(a);
size_t cd = pt->size();
size_t cd1 = eta->size();
size_t cd2 = phi->size();
size_t cd3 = e->size();
 
//std::cout<<"size of pt vec"<<cd<<"\n"<<endl;
for ( size_t i = 0; i!=cd; ++i ) {
aa=pt[0][i];
ht->Fill(aa);
}
//std::cout <<"The value of element"<< i<<"is"<< pt[0][i]<< std::endl;}
 for ( size_t i = 0; i!=cd1; ++i ) {
aa=eta[0][i];
ht2->Fill(aa);
}
for ( size_t i = 0; i!=cd2; ++i ) {
aa=phi[0][i];
ht3->Fill(aa);
}
for ( size_t i = 0; i!=cd3; ++i ) {
aa=e[0][i];
ht4->Fill(aa);
}

l1.SetPtEtaPhiE(pt[0][0],eta[0][0],phi[0][0],e[0][0]);
l2.SetPtEtaPhiE(pt[0][1],eta[0][1],phi[0][1],e[0][1]);
l=l1+l2;
a2=l.M();
ht5->Fill(a2);
}
auto *c=new TCanvas();
c->Divide(3,2);
c->cd(1);
ht1->Draw();
c->cd(2);
gPad->SetLogy();
ht->Draw();
c->cd(3);
ht2->Draw();
c->cd(4);
ht3->Draw();
c->cd(5);
gPad->SetLogy();
ht4->Draw();

c->cd(6);
ht5->Draw();
ht5->Fit("gs","R");
ht5->Draw("same");
c->SaveAs("Ele_Gen_Pt_histo.pdf");
}
