#ifndef  AliAnalysisTaskGetHadrons_H
#define  AliAnalysisTaskGetHadrons_H

#include "AliAnalysisTaskSE.h"

class  AliAnalysisTaskGetHadrons : public  AliAnalysisTaskSE
{
public:
  //  two  class  constructors
  AliAnalysisTaskGetHadrons ();
  AliAnalysisTaskGetHadrons(const  char *name);

  //  class  destructor
  virtual ~AliAnalysisTaskGetHadrons ();

  //  called  once  at  beginning  of  runtime
  virtual  void  UserCreateOutputObjects ();

  //  called  for  each  event
  virtual  void  UserExec(Option_t* option);

  //  called  at  end  of  analysis
  virtual  void  Terminate(Option_t* option);

  

private:
  AliAODEvent* fAOD; //!  input  event
  TList* fOutputList; //!  output  list
  TH1F*  fHistPt; //!  dummy  histogram

  AliAnalysisTaskGetHadrons(const AliAnalysisTaskGetHadrons&); // not implemented
  AliAnalysisTaskGetHadrons& operator=(const AliAnalysisTaskGetHadrons&); // not implemented

  ClassDef(AliAnalysisTaskGetHadrons , 1);
};

#endif
