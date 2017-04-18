#ifndef  AliAnalysisTaskMyTask_H
#define  AliAnalysisTaskMyTask_H

class  AliAnalysisTaskMyTask : public  AliAnalysisTaskSE
{
public:
  //  two  class  constructors
  AliAnalysisTaskMyTask ();
  AliAnalysisTaskMyTask(const  char *name);

  //  class  destructor
  virtual ~AliAnalysisTaskMyTask ();

  //  called  once  at  beginning  of  runtime
  virtual  void  UserCreateOutputObjects ();

  //  called  for  each  event
  virtual  void  serExec(Option_t* option);

  //  called  at  end  of  analysis
  virtual  void  Terminate(Option_t* option);

  ClassDef(AliAnalysisTaskMyTask , 1);

private:
  AliAODEvent* fAOD; //!  input  event
  TList* fOutputList; //!  output  list
  TH1F*  fHistPt; //!  dummy  histogram
};
#endif
