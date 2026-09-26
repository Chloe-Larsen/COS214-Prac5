#ifndef MEDICALRESPONDER_H
#define MEDICALRESPONDER_H

#include "ResponseUnit.h"
#include "Incident.h"

class MedicalResponder : public ResponseUnit {
public:
	MedicalResponder(std::string unitName);
	~MedicalResponder();
	void dispatch(Incident* incident) override;
};

#endif
