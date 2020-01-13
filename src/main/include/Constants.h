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
        constexpr int CHASSIS_LEFT_MOTOR_ID = 0;
        constexpr int CHASSIS_RIGHT_MOTOR_ID = 1;
}  // namespace chassis
    namespace magazine {
        constexpr int MAGAZINE_SPIN_A_MOTOR_ID = 2;
        constexpr int MAGAZINE_SPIN_B_MOTOR_ID = 3;
}  // namespace magazine
    namespace intake {
        constexpr int INTAKE_SPIN_MOTOR_ID = 4;
}  // namespace intake
    namespace turret {
        constexpr int TURRET_SPIN_MOTOR_ID = 5;
        constexpr int TURRET_SHOOT_MOTOR_ID = 6;
}  // namespace turret
}  // namespace constants

#endif