/*#include <TGeoManager.h>
#include <TFile.h>
#include <AliVEvent.h>
#include <AliESDEvent.h>
#include <AliESDHeader.h>
#include <AliVTrack.h>
#include <AliVCluster.h>
#include <AliVCaloCells.h>
#include <AliOADBContainer.h>//*/

#include "TList.h"
#include "TChain.h"
#include "TH1F.h"
#include "AliAODEvent.h"
#include "AliAODInputHandler.h"
#include "AliAnalysisTask.h"
#include "AliAnalysisManager.h"

#include "AliAnalysisTaskGetHadrons.h"

class AliAnalysisTaskGetHadrons; //you analysis class

using namespace std;             

ClassImp(AliAnalysisTaskGetHadrons) //classimp: needed for root

AliAnalysisTaskGetHadrons::AliAnalysisTaskGetHadrons() : AliAnalysisTaskSE(), 
  fAOD(0), fOutputList(0), fHistPt(0)
{
  //ROOT IO constructor, no memory allocation here.
  //Needs to be empty
}
//_______________________________________________________________________
AliAnalysisTaskGetHadrons::AliAnalysisTaskGetHadrons(const char *name) : AliAnalysisTaskSE(name),
  fAOD(0), fOutputList(0), fHistPt(0)
{
  DefineInput (0, TChain ::Class ());
  DefineOutput(1, TList::Class());
}
//_______________________________________________________________________
AliAnalysisTaskGetHadrons::~AliAnalysisTaskGetHadrons()
{
  // destructor
  if(fOutputList) 
    {
      delete fOutputList;
    }
}
//_______________________________________________________________________
void AliAnalysisTaskGetHadrons :: UserCreateOutputObjects ()
{
  //  create  a new  TList  that  OWNS  its  objects
  fOutputList = new  TList();
  fOutputList ->SetOwner(kTRUE);
  //  create  our  histo  and  add  it  to  the  list
  fHistPt = new  TH1F("fHistPt", "fHistPt", 100, 0, 100);
  fOutputList ->Add(fHistPt);
  //  add  the  list  to  our  output  file
  PostData(1, fOutputList);
}
//________________________________________________________________________
void AliAnalysisTaskGetHadrons :: UserExec(Option_t *)
{
  //  get  an  event  from  the  analysis  manager
  fAOD = dynamic_cast <AliAODEvent *>(InputEvent ());
  //  check  if  there  actually  is an  event
  if(!fAOD)
    return;
  //  let ’s loop  over  the  trakcs  and  fill  our  histogram
  Int_t  iTracks(fAOD->GetNumberOfTracks());
  for(Int_t i(0); i < iTracks; i++)
    {
      //  loop  over  all  the  tracks
      AliAODTrack* track = static_cast <AliAODTrack *>(fAOD->GetTrack(i));
      if(! track) 
	continue;
      //  fill  our  histogram
      fHistPt->Fill(track ->Pt());
    }
  //  and  save  the  data  gathered  in  this  iteration
  PostData(1,  fOutputList);
}
//_____________________________________________________________________________
void AliAnalysisTaskGetHadrons::Terminate(Option_t *)
{
  cout << "Analysis is running Terminate" << endl;
    // terminate
    // called at the END of the analysis (when all events are processed)
}
//_____________________________________________________________________________


