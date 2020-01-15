#include "subsystems/JetsonNanoCamera.h"
#include "networktables/NetworkTable.h"

#include "frc/smartdashboard/SmartDashboard.h"

JetsonNanoCamera::JetsonNanoCamera() {
    auto m_networkTable =
        nt::NetworkTableInstance::GetDefault().GetTable("JETSONNANO");

    m_targetXEntry = m_networkTable->GetEntry("TargetX");
    m_targetYEntry = m_networkTable->GetEntry("TargetY");

    m_actualXEntry = m_networkTable->GetEntry("ActualX");
    m_actualYEntry = m_networkTable->GetEntry("ActualY");

    std::cout << "the subsystem Jetson Nano & Camera instantiate!" << std::endl;
}

void JetsonNanoCamera::RegisterState(
    SuperStructureSate* tempSuperStructureState) {
    m_superStructureState = tempSuperStructureState;
}

void JetsonNanoCamera::ReadInput() {
    m_periodicIO.m_i_targetX = m_targetXEntry.GetDouble(0.0);
    m_periodicIO.m_i_targetY = m_targetYEntry.GetDouble(0.0);

    m_periodicIO.m_i_actualX = m_actualXEntry.GetDouble(0.0);
    m_periodicIO.m_i_actualY = m_actualYEntry.GetDouble(0.0);
}

void JetsonNanoCamera::WriteOutput() {
    m_superStructureState->m_targetX = m_periodicIO.m_i_targetX;
    m_superStructureState->m_targetY = m_periodicIO.m_i_targetY;

    m_superStructureState->m_actualX = m_periodicIO.m_i_actualX;
    m_superStructureState->m_actualY = m_periodicIO.m_i_actualY;
}

void JetsonNanoCamera::ZeroSensors() {
    m_periodicIO.m_i_targetX = 0;
    m_periodicIO.m_i_targetY = 0;

    m_periodicIO.m_i_actualX = 0;
    m_periodicIO.m_i_actualY = 0;
}

void JetsonNanoCamera::PrintToLog() {
    frc::SmartDashboard::PutNumber("Hole target X", m_periodicIO.m_i_targetX);
    frc::SmartDashboard::PutNumber("Hole target Y", m_periodicIO.m_i_targetY);

    frc::SmartDashboard::PutNumber("Hole actual X", m_periodicIO.m_i_actualX);
    frc::SmartDashboard::PutNumber("Hole actual Y", m_periodicIO.m_i_actualY);
}