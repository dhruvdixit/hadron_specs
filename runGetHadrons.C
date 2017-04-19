void  runGetHadrons()
{
  //  header  location
  gROOT ->ProcessLine(".include  $ROOTSYS/include");
  gROOT ->ProcessLine(".include  $ALICE_ROOT/include");

  /*// Load base root libraries
  gSystem->Load("libTree");
  gSystem->Load("libGeom");
  gSystem->Load("libVMC");
  gSystem->Load("libSTEERBase");
  gSystem->Load("libPhysics");
  gSystem->Load("libESD");
  gSystem->Load("libAOD");
  
  // Load analysis framework libraries
  gSystem->Load("libANALYSIS");
  gSystem->Load("libANALYSISalice");
  gSystem->Load("libEMCALUtils");
  gSystem->Load("libPWGPPEMCAL");//*/
  
  //  create  the  analysis  manager
  AliAnalysisManager *mgr = new  AliAnalysisManager("AnalysisTaskHadronPt");
  AliAODInputHandler *aodH = new  AliAODInputHandler ();
  mgr ->SetInputEventHandler(aodH);

  //  compile  the  class (locally)
  gROOT ->LoadMacro("AliAnalysisTaskGetHadrons.cxx++g");

  //  load  the  add task  macro
  gROOT->LoadMacro("macros/AddAliAnalysisTaskGetHadrons.C");

  //  create  an  instance  of  your  analysis  task
  AliAnalysisTaskGetHadrons *task = AddAliAnalysisTaskGetHadrons();

  if(!mgr->InitAnalysis()) 
    return;
  mgr->SetDebugLevel(2);
  mgr->PrintStatus();
  mgr->SetUseProgressBar(1, 25);

  //  if  you  want  to  run  locally , we  need  to  define  some  input
  TChain* chain = new  TChain("aodTree");
  chain ->Add("/global/homes/d/ddixit/alice/data/2015/LHC15o/000245700/pass1/AOD/005/AliAOD.root");

  //  start  the  analysis  locally
  mgr ->StartAnalysis("local", chain);
}
