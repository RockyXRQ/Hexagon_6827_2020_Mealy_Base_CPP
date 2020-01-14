#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace constants {
    namespace joystick {
        constexpr int JOYSTICK_DRIVE_PORT = 0;
        constexpr int JOYSTICK_SUPERSTRUCTURE_PORT = 1;

        constexpr double JOYSTICK_DRIVE_STRIGHT_DEAD_AREA = 0.2;
        constexpr double JOYSTICK_DRIVE_TURN_DEAD_AREA = 0.2;
    }  // namespace jotstick
    namespace chassis {
        constexpr double CHASSIS_KP = 0;
        constexpr double CHASSIS_KI = 0;
        constexpr double CHASSIS_KD = 0;

        constexpr int CHASSIS_LEFT_MOTOR_ID = 0;
        constexpr int CHASSIS_RIGHT_MOTOR_ID = 1;
    }  // namespace chassis
    namespace magazine {
        constexpr double MAGAZINE_KP = 0;
        constexpr double MAGAZINE_KI = 0;
        constexpr double MAGAZINE_KD = 0;
        
        constexpr int MAGAZINE_SPIN_A_MOTOR_ID = 2;
        constexpr int MAGAZINE_SPIN_B_MOTOR_ID = 3;
    }  // namespace magazine
    namespace intake {
        constexpr double INTAKE_KP = 0;
        constexpr double INTAKE_KI = 0;
        constexpr double INTAKE_KD = 0;
        
        constexpr int INTAKE_SPIN_MOTOR_ID = 4;
    }  // namespace intake
    namespace turret {
        constexpr double TURRET_KP = 0;
        constexpr double TURRET_KI = 0;
        constexpr double TURRET_KD = 0;

        constexpr int TURRET_AIM_SERVO_CHANNEL = 3;
        constexpr int TURRET_SPIN_MOTOR_ID = 5;
        constexpr int TURRET_SHOOT_MOTOR_ID = 6;

        constexpr double SERVO_HIGH_POSITION = 1;
        constexpr double SERVO_LOW_POSITION = 0;
    }  // namespace turret
    namespace gear{
        constexpr double GEAR_KP = 0;
        constexpr double GEAR_KI = 0;
        constexpr double GEAR_KD = 0;

        constexpr int GEAR_ARM_MOTOR_ID = 7;
        constexpr int GEAR_HAND_MOTOR_ID =8;
    }
}  // namespace constants

#endif