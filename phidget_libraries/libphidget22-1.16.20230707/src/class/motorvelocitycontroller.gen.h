#ifndef _MOTORVELOCITYCONTROLLER_H_
#define _MOTORVELOCITYCONTROLLER_H_

/* Generated by WriteClassHeaderVisitor: Fri Jul 07 2023 09:13:04 GMT-0600 (Mountain Daylight Time) */

#ifdef INCLUDE_PRIVATE
typedef struct _PhidgetMotorVelocityController *PhidgetMotorVelocityControllerHandle;

/* Methods */
API_PRETURN_HDR PhidgetMotorVelocityController_create(PhidgetMotorVelocityControllerHandle *ch);
API_PRETURN_HDR PhidgetMotorVelocityController_delete(PhidgetMotorVelocityControllerHandle *ch);
API_PRETURN_HDR PhidgetMotorVelocityController_enableFailsafe(PhidgetMotorVelocityControllerHandle ch,
  uint32_t failsafeTime);
API_PRETURN_HDR PhidgetMotorVelocityController_resetFailsafe(PhidgetMotorVelocityControllerHandle ch);

/* Properties */
API_PRETURN_HDR PhidgetMotorVelocityController_setAcceleration(PhidgetMotorVelocityControllerHandle ch,
  double acceleration);
API_PRETURN_HDR PhidgetMotorVelocityController_getAcceleration(PhidgetMotorVelocityControllerHandle ch,
  double *acceleration);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinAcceleration(PhidgetMotorVelocityControllerHandle ch,
  double *minAcceleration);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxAcceleration(PhidgetMotorVelocityControllerHandle ch,
  double *maxAcceleration);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinBrakingStrength(PhidgetMotorVelocityControllerHandle ch, double *minBrakingStrength);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxBrakingStrength(PhidgetMotorVelocityControllerHandle ch, double *maxBrakingStrength);
API_PRETURN_HDR PhidgetMotorVelocityController_setCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double currentLimit);
API_PRETURN_HDR PhidgetMotorVelocityController_getCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double *currentLimit);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double *minCurrentLimit);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double *maxCurrentLimit);
API_PRETURN_HDR PhidgetMotorVelocityController_setDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t dataInterval);
API_PRETURN_HDR PhidgetMotorVelocityController_getDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *dataInterval);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *minDataInterval);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *maxDataInterval);
API_PRETURN_HDR PhidgetMotorVelocityController_setDataRate(PhidgetMotorVelocityControllerHandle ch,
  double dataRate);
API_PRETURN_HDR PhidgetMotorVelocityController_getDataRate(PhidgetMotorVelocityControllerHandle ch,
  double *dataRate);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinDataRate(PhidgetMotorVelocityControllerHandle ch,
  double *minDataRate);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxDataRate(PhidgetMotorVelocityControllerHandle ch,
  double *maxDataRate);
API_PRETURN_HDR PhidgetMotorVelocityController_setDeadBand(PhidgetMotorVelocityControllerHandle ch,
  double deadBand);
API_PRETURN_HDR PhidgetMotorVelocityController_getDeadBand(PhidgetMotorVelocityControllerHandle ch,
  double *deadBand);
API_PRETURN_HDR PhidgetMotorVelocityController_getDutyCycle(PhidgetMotorVelocityControllerHandle ch,
  double *dutyCycle);
API_PRETURN_HDR PhidgetMotorVelocityController_setEngaged(PhidgetMotorVelocityControllerHandle ch,
  int engaged);
API_PRETURN_HDR PhidgetMotorVelocityController_getEngaged(PhidgetMotorVelocityControllerHandle ch,
  int *engaged);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinFailsafeTime(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *minFailsafeTime);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxFailsafeTime(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *maxFailsafeTime);
API_PRETURN_HDR PhidgetMotorVelocityController_setKd(PhidgetMotorVelocityControllerHandle ch,
  double kd);
API_PRETURN_HDR PhidgetMotorVelocityController_getKd(PhidgetMotorVelocityControllerHandle ch,
  double *kd);
API_PRETURN_HDR PhidgetMotorVelocityController_setKi(PhidgetMotorVelocityControllerHandle ch,
  double ki);
API_PRETURN_HDR PhidgetMotorVelocityController_getKi(PhidgetMotorVelocityControllerHandle ch,
  double *ki);
API_PRETURN_HDR PhidgetMotorVelocityController_setKp(PhidgetMotorVelocityControllerHandle ch,
  double kp);
API_PRETURN_HDR PhidgetMotorVelocityController_getKp(PhidgetMotorVelocityControllerHandle ch,
  double *kp);
API_PRETURN_HDR PhidgetMotorVelocityController_setMotorInductance(PhidgetMotorVelocityControllerHandle ch,
  double motorInductance);
API_PRETURN_HDR PhidgetMotorVelocityController_getMotorInductance(PhidgetMotorVelocityControllerHandle ch,
  double *motorInductance);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinMotorInductance(PhidgetMotorVelocityControllerHandle ch, double *minMotorInductance);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxMotorInductance(PhidgetMotorVelocityControllerHandle ch, double *maxMotorInductance);
API_PRETURN_HDR PhidgetMotorVelocityController_setMotorPositionType(PhidgetMotorVelocityControllerHandle ch, Phidget_MotorPositionType motorPositionType);
API_PRETURN_HDR PhidgetMotorVelocityController_getMotorPositionType(PhidgetMotorVelocityControllerHandle ch, Phidget_MotorPositionType *motorPositionType);
API_PRETURN_HDR PhidgetMotorVelocityController_setRescaleFactor(PhidgetMotorVelocityControllerHandle ch,
  double rescaleFactor);
API_PRETURN_HDR PhidgetMotorVelocityController_getRescaleFactor(PhidgetMotorVelocityControllerHandle ch,
  double *rescaleFactor);
API_PRETURN_HDR PhidgetMotorVelocityController_setStallVelocity(PhidgetMotorVelocityControllerHandle ch,
  double stallVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getStallVelocity(PhidgetMotorVelocityControllerHandle ch,
  double *stallVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinStallVelocity(PhidgetMotorVelocityControllerHandle ch, double *minStallVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxStallVelocity(PhidgetMotorVelocityControllerHandle ch, double *maxStallVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_setTargetBrakingStrength(PhidgetMotorVelocityControllerHandle ch, double targetBrakingStrength);
API_PRETURN_HDR PhidgetMotorVelocityController_getTargetBrakingStrength(PhidgetMotorVelocityControllerHandle ch, double *targetBrakingStrength);
API_PRETURN_HDR PhidgetMotorVelocityController_setTargetVelocity(PhidgetMotorVelocityControllerHandle ch,
  double targetVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getTargetVelocity(PhidgetMotorVelocityControllerHandle ch,
  double *targetVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getMinTargetVelocity(PhidgetMotorVelocityControllerHandle ch, double *minTargetVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getMaxTargetVelocity(PhidgetMotorVelocityControllerHandle ch, double *maxTargetVelocity);
API_PRETURN_HDR PhidgetMotorVelocityController_getVelocity(PhidgetMotorVelocityControllerHandle ch,
  double *velocity);

/* Events */
typedef void (CCONV *PhidgetMotorVelocityController_OnDutyCycleUpdateCallback)(PhidgetMotorVelocityControllerHandle ch, void *ctx, double dutyCycle);

API_PRETURN_HDR PhidgetMotorVelocityController_setOnDutyCycleUpdateHandler(PhidgetMotorVelocityControllerHandle ch, PhidgetMotorVelocityController_OnDutyCycleUpdateCallback fptr, void *ctx);
typedef void (CCONV *PhidgetMotorVelocityController_OnVelocityChangeCallback)(PhidgetMotorVelocityControllerHandle ch, void *ctx, double velocity);

API_PRETURN_HDR PhidgetMotorVelocityController_setOnVelocityChangeHandler(PhidgetMotorVelocityControllerHandle ch, PhidgetMotorVelocityController_OnVelocityChangeCallback fptr, void *ctx);

#endif /* INCLUDE_PRIVATE */
#endif /* _MOTORVELOCITYCONTROLLER_H_ */
