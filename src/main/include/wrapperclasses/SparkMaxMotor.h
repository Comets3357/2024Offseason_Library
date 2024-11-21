# pragma once 

#include "wrapperclasses/Motor.h"

//#include <ClosedLoopConfig.h>
#include <rev/SparkMax.h>
#include <rev/SparkBase.h>
//#include <SparkBaseConfig.h> 


class SparkMaxMotor : public Motor {
    private: 
        rev::spark::SparkMax motor; 
        rev::spark::SparkAbsoluteEncoder AbsoluteEncoder = motor.GetAbsoluteEncoder(); 
        rev::spark::SparkRelativeEncoder RelativeEncoder = motor.GetEncoder(); 
        rev::spark::SparkBaseConfig config; 
        rev::spark::ClosedLoopConfig closedLoopConfig; 
        rev::spark::SoftLimitConfig softLimitConfig; 



    public: 
        SparkMaxMotor(int id) : motor{id, rev::spark::SparkLowLevel::MotorType::kBrushless} 
        {
            setPID(0, 0, 0); 
        }

        // rev::spark::SparkBaseConfig::SparkBaseConfig name{}

        void SetPercent(double percent) override;
        void StopMotor() override; 

        double GetRelativeVelocity() override; 
        double GetRelativePosition() override;
        double SetRelativePosition(double pos) override;

        // CONFIGURE SETTINGS // 

        void configure() override; 
        void setPID(double p, double i, double d, double ff) override; 
        void setPID(double p, double i, double d) override; 

        void setForwardSoftLimit(double limit) override; 
        void setReverseSoftLimit(double limit) override; 
        void enableForwardSoftLimit(bool enab) override; 
        void enableReverseSoftLimit(bool enab) override; 

        virtual void setInverted(bool b) override; 

        //SparkMotor.Configure(struct 1, enum 2, enum 3); 
}; 
 