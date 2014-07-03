#ifndef EventViewBase_h
#define EventViewBase_h

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "TTree.h"
#include <algorithm>
#include "DataFormats/Candidate/interface/Candidate.h"

class EventViewBase {
   public:
      EventViewBase() {};
      EventViewBase(const edm::ParameterSet&, TTree * tree);
      virtual void fill(const edm::Event&, const edm::EventSetup&) = 0;
      ~EventViewBase();

    protected:
      void resetVariables();
      void registerInt(std::string name,  TTree * tree);
      void registerFloat(std::string name, TTree * tree);
      void registerVecP4(std::string name,  TTree * tree);
      void registerVecInt(std::string name,  TTree * tree);


   private:
      std::map<std::string, int> m_integerBranches;
      std::map<std::string, float> m_floatBranches;
      std::map<std::string, std::vector<reco::Candidate::LorentzVector> > m_vectorBranches;
      std::map<std::string, std::vector<int> > m_vecIntBranches;

};
#endif