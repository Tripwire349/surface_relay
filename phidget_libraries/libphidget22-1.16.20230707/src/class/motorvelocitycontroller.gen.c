/* Generated: Fri Jul 07 2023 09:13:04 GMT-0600 (Mountain Daylight Time) */

static void CCONV PhidgetMotorVelocityController_errorHandler(PhidgetChannelHandle ch,
  Phidget_ErrorEventCode code);
static void CCONV PhidgetMotorVelocityController_free(PhidgetChannelHandle *ch);
static PhidgetReturnCode CCONV PhidgetMotorVelocityController_bridgeInput(PhidgetChannelHandle phid,
  BridgePacket *bp);
static PhidgetReturnCode CCONV PhidgetMotorVelocityController_setStatus(PhidgetChannelHandle phid,
  BridgePacket *bp);
static PhidgetReturnCode CCONV PhidgetMotorVelocityController_getStatus(PhidgetChannelHandle phid,
  BridgePacket **bp);
static PhidgetReturnCode CCONV PhidgetMotorVelocityController_initAfterOpen(PhidgetChannelHandle phid);
static PhidgetReturnCode CCONV PhidgetMotorVelocityController_setDefaults(PhidgetChannelHandle phid);
static void CCONV PhidgetMotorVelocityController_fireInitialEvents(PhidgetChannelHandle phid);
static int CCONV PhidgetMotorVelocityController_hasInitialState(PhidgetChannelHandle phid);

struct _PhidgetMotorVelocityController {
	struct _PhidgetChannel phid;
	double acceleration;
	double minAcceleration;
	double maxAcceleration;
	double minBrakingStrength;
	double maxBrakingStrength;
	double currentLimit;
	double minCurrentLimit;
	double maxCurrentLimit;
	double dataInterval;
	uint32_t minDataInterval;
	uint32_t maxDataInterval;
	double minDataRate;
	double maxDataRate;
	double deadBand;
	double dutyCycle;
	int engaged;
	uint32_t minFailsafeTime;
	uint32_t maxFailsafeTime;
	double kd;
	double ki;
	double kp;
	double motorInductance;
	double minMotorInductance;
	double maxMotorInductance;
	Phidget_MotorPositionType motorPositionType;
	double rescaleFactor;
	double stallVelocity;
	double minStallVelocity;
	double maxStallVelocity;
	double targetBrakingStrength;
	double targetVelocity;
	double minTargetVelocity;
	double maxTargetVelocity;
	double velocity;
	PhidgetMotorVelocityController_OnDutyCycleUpdateCallback DutyCycleUpdate;
	void *DutyCycleUpdateCtx;
	PhidgetMotorVelocityController_OnVelocityChangeCallback VelocityChange;
	void *VelocityChangeCtx;
};

static PhidgetReturnCode CCONV
_setStatus(PhidgetChannelHandle phid, BridgePacket *bp) {
	PhidgetMotorVelocityControllerHandle ch;
	int version;

	ch = (PhidgetMotorVelocityControllerHandle)phid;

	version = getBridgePacketUInt32ByName(bp, "_class_version_");
	if (version != 1) {
		loginfo("%"PRIphid": server/client class version mismatch: %d != 1 - functionality may be limited.", phid, version);
	}

	if (version >= 0)
		ch->acceleration = getBridgePacketDoubleByName(bp, "acceleration");
	if (version >= 0)
		ch->minAcceleration = getBridgePacketDoubleByName(bp, "minAcceleration");
	if (version >= 0)
		ch->maxAcceleration = getBridgePacketDoubleByName(bp, "maxAcceleration");
	if (version >= 0)
		ch->minBrakingStrength = getBridgePacketDoubleByName(bp, "minBrakingStrength");
	if (version >= 0)
		ch->maxBrakingStrength = getBridgePacketDoubleByName(bp, "maxBrakingStrength");
	if (version >= 0)
		ch->currentLimit = getBridgePacketDoubleByName(bp, "currentLimit");
	if (version >= 0)
		ch->minCurrentLimit = getBridgePacketDoubleByName(bp, "minCurrentLimit");
	if (version >= 0)
		ch->maxCurrentLimit = getBridgePacketDoubleByName(bp, "maxCurrentLimit");
	if (version >= 0)
		ch->minDataInterval = getBridgePacketUInt32ByName(bp, "minDataInterval");
	if (version >= 0)
		ch->maxDataInterval = getBridgePacketUInt32ByName(bp, "maxDataInterval");
	if (version >= 0)
		ch->dataInterval = getBridgePacketDoubleByName(bp, "dataIntervalDbl");
	else if(version >= 0)
		ch->dataInterval = (double)getBridgePacketUInt32ByName(bp, "dataInterval");
	if (version >= 0)
		ch->minDataRate = getBridgePacketDoubleByName(bp, "minDataRate");
	else if(version >= 0)
		ch->minDataRate = (double)(1000.0 / getBridgePacketUInt32ByName(bp, "maxDataInterval"));
	if (version >= 0)
		ch->maxDataRate = getBridgePacketDoubleByName(bp, "maxDataRate");
	else if(version >= 0)
		ch->maxDataRate = (double)(1000.0 / getBridgePacketUInt32ByName(bp, "minDataInterval"));
	if (version >= 0)
		ch->deadBand = getBridgePacketDoubleByName(bp, "deadBand");
	if (version >= 0)
		ch->dutyCycle = getBridgePacketDoubleByName(bp, "dutyCycle");
	if (version >= 0)
		ch->engaged = getBridgePacketInt32ByName(bp, "engaged");
	if (version >= 0)
		ch->minFailsafeTime = getBridgePacketUInt32ByName(bp, "minFailsafeTime");
	if (version >= 0)
		ch->maxFailsafeTime = getBridgePacketUInt32ByName(bp, "maxFailsafeTime");
	if (version >= 0)
		ch->kd = getBridgePacketDoubleByName(bp, "kd");
	if (version >= 0)
		ch->ki = getBridgePacketDoubleByName(bp, "ki");
	if (version >= 0)
		ch->kp = getBridgePacketDoubleByName(bp, "kp");
	if (version >= 0)
		ch->motorInductance = getBridgePacketDoubleByName(bp, "motorInductance");
	if (version >= 0)
		ch->minMotorInductance = getBridgePacketDoubleByName(bp, "minMotorInductance");
	if (version >= 0)
		ch->maxMotorInductance = getBridgePacketDoubleByName(bp, "maxMotorInductance");
	if (version >= 0)
		ch->motorPositionType = getBridgePacketInt32ByName(bp, "motorPositionType");
	if (version >= 0)
		ch->rescaleFactor = getBridgePacketDoubleByName(bp, "rescaleFactor");
	if (version >= 0)
		ch->stallVelocity = getBridgePacketDoubleByName(bp, "stallVelocity");
	if (version >= 0)
		ch->minStallVelocity = getBridgePacketDoubleByName(bp, "minStallVelocity");
	if (version >= 0)
		ch->maxStallVelocity = getBridgePacketDoubleByName(bp, "maxStallVelocity");
	if (version >= 0)
		ch->targetBrakingStrength = getBridgePacketDoubleByName(bp, "targetBrakingStrength");
	if (version >= 0)
		ch->targetVelocity = getBridgePacketDoubleByName(bp, "targetVelocity");
	if (version >= 0)
		ch->minTargetVelocity = getBridgePacketDoubleByName(bp, "minTargetVelocity");
	if (version >= 0)
		ch->maxTargetVelocity = getBridgePacketDoubleByName(bp, "maxTargetVelocity");
	if (version >= 0)
		ch->velocity = getBridgePacketDoubleByName(bp, "velocity");

	return (EPHIDGET_OK);
}

static PhidgetReturnCode CCONV
_getStatus(PhidgetChannelHandle phid, BridgePacket **bp) {
	PhidgetMotorVelocityControllerHandle ch;

	ch = (PhidgetMotorVelocityControllerHandle)phid;

	return (createBridgePacket(bp, BP_SETSTATUS, 36, "_class_version_=%u"
	  ",acceleration=%g"
	  ",minAcceleration=%g"
	  ",maxAcceleration=%g"
	  ",minBrakingStrength=%g"
	  ",maxBrakingStrength=%g"
	  ",currentLimit=%g"
	  ",minCurrentLimit=%g"
	  ",maxCurrentLimit=%g"
	  ",dataInterval=%u"
	  ",minDataInterval=%u"
	  ",maxDataInterval=%u"
	  ",dataIntervalDbl=%g"
	  ",minDataRate=%g"
	  ",maxDataRate=%g"
	  ",deadBand=%g"
	  ",dutyCycle=%g"
	  ",engaged=%d"
	  ",minFailsafeTime=%u"
	  ",maxFailsafeTime=%u"
	  ",kd=%g"
	  ",ki=%g"
	  ",kp=%g"
	  ",motorInductance=%g"
	  ",minMotorInductance=%g"
	  ",maxMotorInductance=%g"
	  ",motorPositionType=%d"
	  ",rescaleFactor=%g"
	  ",stallVelocity=%g"
	  ",minStallVelocity=%g"
	  ",maxStallVelocity=%g"
	  ",targetBrakingStrength=%g"
	  ",targetVelocity=%g"
	  ",minTargetVelocity=%g"
	  ",maxTargetVelocity=%g"
	  ",velocity=%g"
	  ,1 /* class version */
	  ,ch->acceleration
	  ,ch->minAcceleration
	  ,ch->maxAcceleration
	  ,ch->minBrakingStrength
	  ,ch->maxBrakingStrength
	  ,ch->currentLimit
	  ,ch->minCurrentLimit
	  ,ch->maxCurrentLimit
	  ,(uint32_t)round(ch->dataInterval)
	  ,ch->minDataInterval
	  ,ch->maxDataInterval
	  ,ch->dataInterval
	  ,ch->minDataRate
	  ,ch->maxDataRate
	  ,ch->deadBand
	  ,ch->dutyCycle
	  ,ch->engaged
	  ,ch->minFailsafeTime
	  ,ch->maxFailsafeTime
	  ,ch->kd
	  ,ch->ki
	  ,ch->kp
	  ,ch->motorInductance
	  ,ch->minMotorInductance
	  ,ch->maxMotorInductance
	  ,ch->motorPositionType
	  ,ch->rescaleFactor
	  ,ch->stallVelocity
	  ,ch->minStallVelocity
	  ,ch->maxStallVelocity
	  ,ch->targetBrakingStrength
	  ,ch->targetVelocity
	  ,ch->minTargetVelocity
	  ,ch->maxTargetVelocity
	  ,ch->velocity
	));
}

static PhidgetReturnCode CCONV
_bridgeInput(PhidgetChannelHandle phid, BridgePacket *bp) {
	PhidgetMotorVelocityControllerHandle ch;
	PhidgetReturnCode res;

	ch = (PhidgetMotorVelocityControllerHandle)phid;
	res = EPHIDGET_OK;

	switch (bp->vpkt) {
	case BP_SETFAILSAFETIME:
		res = DEVBRIDGEINPUT(phid, bp);
		break;
	case BP_FAILSAFERESET:
		res = DEVBRIDGEINPUT(phid, bp);
		break;
	case BP_SETACCELERATION:
		TESTRANGE_IOP(bp->iop, "%lf", getBridgePacketDouble(bp, 0), ch->minAcceleration,
		  ch->maxAcceleration);
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->acceleration = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "Acceleration");
		}
		break;
	case BP_SETCURRENTLIMIT:
		TESTRANGE_IOP(bp->iop, "%lf", getBridgePacketDouble(bp, 0), ch->minCurrentLimit,
		  ch->maxCurrentLimit);
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->currentLimit = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "CurrentLimit");
		}
		break;
	case BP_SETDATAINTERVAL:
		if (bp->entrycnt > 1)
			TESTRANGE_IOP(bp->iop, "%lf", round_double((1000.0 / getBridgePacketDouble(bp, 1)), 4),
			  ch->minDataRate, ch->maxDataRate);
		else
			TESTRANGE_IOP(bp->iop, "%"PRIu32, getBridgePacketUInt32(bp, 0), ch->minDataInterval,
			  ch->maxDataInterval);
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		if (bp->entrycnt > 1)
			ch->dataInterval = getBridgePacketDouble(bp, 1);
		else
			ch->dataInterval = (double)getBridgePacketUInt32(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "DataInterval");
			FIRE_PROPERTYCHANGE(ch, "DataRate");
		}
		break;
	case BP_SETDEADBAND:
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->deadBand = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "DeadBand");
		}
		break;
	case BP_SETENGAGED:
		TESTBOOL_IOP(bp->iop, getBridgePacketInt32(bp, 0));
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->engaged = getBridgePacketInt32(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "Engaged");
		}
		break;
	case BP_SETKD:
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->kd = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "Kd");
		}
		break;
	case BP_SETKI:
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->ki = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "Ki");
		}
		break;
	case BP_SETKP:
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->kp = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "Kp");
		}
		break;
	case BP_SETMOTORINDUCTANCE:
		TESTRANGE_IOP(bp->iop, "%lf", getBridgePacketDouble(bp, 0), ch->minMotorInductance,
		  ch->maxMotorInductance);
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->motorInductance = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "MotorInductance");
		}
		break;
	case BP_MOTORPOSITIONTYPE:
		if (!supportedMotorPositionType(phid, (Phidget_MotorPositionType)getBridgePacketInt32(bp, 0)))
			return (MOS_ERROR(bp->iop, EPHIDGET_INVALIDARG,
			  "Specified MotorPositionType is unsupported by this device."));
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->motorPositionType = getBridgePacketInt32(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "MotorPositionType");
		}
		break;
	case BP_SETSTALLVELOCITY:
		TESTRANGE_IOP(bp->iop, "%lf", getBridgePacketDouble(bp, 0), ch->minStallVelocity,
		  ch->maxStallVelocity);
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->stallVelocity = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "StallVelocity");
		}
		break;
	case BP_SETBRAKINGDUTYCYCLE:
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->targetBrakingStrength = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "TargetBrakingStrength");
		}
		break;
	case BP_SETDUTYCYCLE:
		TESTRANGE_IOP(bp->iop, "%lf", getBridgePacketDouble(bp, 0), ch->minTargetVelocity,
		  ch->maxTargetVelocity);
		res = DEVBRIDGEINPUT(phid, bp);
		if (res != EPHIDGET_OK)
			break;
		ch->targetVelocity = getBridgePacketDouble(bp, 0);
		if (bridgePacketIsFromNet(bp)) {
			FIRE_PROPERTYCHANGE(ch, "TargetVelocity");
		}
		break;
	case BP_DUTYCYCLECHANGE:
		ch->dutyCycle = getBridgePacketDouble(bp, 0);
		FIRECH(ch, DutyCycleUpdate, ch->dutyCycle);
		break;
	default:
		logerr("%"PRIphid": unsupported bridge packet:0x%x", phid, bp->vpkt);
		res = EPHIDGET_UNSUPPORTED;
	}

	return (res);
}

static PhidgetReturnCode CCONV
_initAfterOpen(PhidgetChannelHandle phid) {
	PhidgetReturnCode ret;

	TESTPTR(phid);

	ret = EPHIDGET_OK;


	switch (phid->UCD->uid) {
	default:
		MOS_PANIC("Unsupported Channel");
	}


	return (ret);
}

static PhidgetReturnCode CCONV
_setDefaults(PhidgetChannelHandle phid) {
	PhidgetReturnCode ret;

	TESTPTR(phid);

	ret = EPHIDGET_OK;

	switch (phid->UCD->uid) {
	default:
		MOS_PANIC("Unsupported Channel");
	}

	return (ret);
}

static void CCONV
_fireInitialEvents(PhidgetChannelHandle phid) {
	PhidgetMotorVelocityControllerHandle ch;

	ch = (PhidgetMotorVelocityControllerHandle)phid;

	if(ch->dutyCycle != PUNK_DBL)
		FIRECH(ch, DutyCycleUpdate, ch->dutyCycle);

}

static int CCONV
_hasInitialState(PhidgetChannelHandle phid) {
	PhidgetMotorVelocityControllerHandle ch;

	ch = (PhidgetMotorVelocityControllerHandle)phid;

	if(ch->dutyCycle == PUNK_DBL)
		return (PFALSE);

	return (PTRUE);
}

static void CCONV
_free(PhidgetChannelHandle *ch) {

	mos_free(*ch, sizeof (struct _PhidgetMotorVelocityController));
}

static PhidgetReturnCode CCONV
_create(PhidgetMotorVelocityControllerHandle *phidp) {

	CHANNELCREATE_BODY(MotorVelocityController, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_delete(PhidgetMotorVelocityControllerHandle *phidp) {

	return (Phidget_delete((PhidgetHandle *)phidp));
}

API_PRETURN
PhidgetMotorVelocityController_enableFailsafe(PhidgetMotorVelocityControllerHandle ch,
  uint32_t failsafeTime) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETFAILSAFETIME, NULL, NULL, 1, "%u",
	  failsafeTime); 
}

API_PRETURN
PhidgetMotorVelocityController_resetFailsafe(PhidgetMotorVelocityControllerHandle ch) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return bridgeSendToDevice((PhidgetChannelHandle)ch, BP_FAILSAFERESET, NULL, NULL, 0, NULL); 
}

API_PRETURN
PhidgetMotorVelocityController_getMinBrakingStrength(PhidgetMotorVelocityControllerHandle ch,
  double *minBrakingStrength) {

	TESTPTR_PR(ch);
	TESTPTR_PR(minBrakingStrength);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*minBrakingStrength = ch->minBrakingStrength;
	if (ch->minBrakingStrength == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMaxBrakingStrength(PhidgetMotorVelocityControllerHandle ch,
  double *maxBrakingStrength) {

	TESTPTR_PR(ch);
	TESTPTR_PR(maxBrakingStrength);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*maxBrakingStrength = ch->maxBrakingStrength;
	if (ch->maxBrakingStrength == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double currentLimit) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return (bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETCURRENTLIMIT, NULL, NULL, 1, "%g",
	  currentLimit));
}

API_PRETURN
PhidgetMotorVelocityController_getCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double *currentLimit) {

	TESTPTR_PR(ch);
	TESTPTR_PR(currentLimit);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*currentLimit = ch->currentLimit;
	if (ch->currentLimit == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMinCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double *minCurrentLimit) {

	TESTPTR_PR(ch);
	TESTPTR_PR(minCurrentLimit);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*minCurrentLimit = ch->minCurrentLimit;
	if (ch->minCurrentLimit == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMaxCurrentLimit(PhidgetMotorVelocityControllerHandle ch,
  double *maxCurrentLimit) {

	TESTPTR_PR(ch);
	TESTPTR_PR(maxCurrentLimit);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*maxCurrentLimit = ch->maxCurrentLimit;
	if (ch->maxCurrentLimit == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t dataInterval) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return (bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETDATAINTERVAL, NULL, NULL, 1, "%u",
	  dataInterval));
}

API_PRETURN
PhidgetMotorVelocityController_getDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *dataInterval) {

	TESTPTR_PR(ch);
	TESTPTR_PR(dataInterval);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*dataInterval = (uint32_t)round(ch->dataInterval);
	if (ch->dataInterval == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMinDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *minDataInterval) {

	TESTPTR_PR(ch);
	TESTPTR_PR(minDataInterval);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*minDataInterval = ch->minDataInterval;
	if (ch->minDataInterval == (uint32_t)PUNK_UINT32)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMaxDataInterval(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *maxDataInterval) {

	TESTPTR_PR(ch);
	TESTPTR_PR(maxDataInterval);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*maxDataInterval = ch->maxDataInterval;
	if (ch->maxDataInterval == (uint32_t)PUNK_UINT32)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setDataRate(PhidgetMotorVelocityControllerHandle ch, double dataRate) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETDATAINTERVAL, NULL, NULL, 2, "%u%g",
	  (uint32_t)round(1000.0 / dataRate), (double)(1000.0 / dataRate));
}

API_PRETURN
PhidgetMotorVelocityController_getDataRate(PhidgetMotorVelocityControllerHandle ch, double *dataRate) {

	TESTPTR_PR(ch);
	TESTPTR_PR(dataRate);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*dataRate = round_double((1000.0 / ch->dataInterval), 4);
	if (ch->dataInterval == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMinDataRate(PhidgetMotorVelocityControllerHandle ch,
  double *minDataRate) {

	TESTPTR_PR(ch);
	TESTPTR_PR(minDataRate);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*minDataRate = ch->minDataRate;
	if (ch->minDataRate == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMaxDataRate(PhidgetMotorVelocityControllerHandle ch,
  double *maxDataRate) {

	TESTPTR_PR(ch);
	TESTPTR_PR(maxDataRate);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*maxDataRate = ch->maxDataRate;
	if (ch->maxDataRate == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getDutyCycle(PhidgetMotorVelocityControllerHandle ch,
  double *dutyCycle) {

	TESTPTR_PR(ch);
	TESTPTR_PR(dutyCycle);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*dutyCycle = ch->dutyCycle;
	if (ch->dutyCycle == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setEngaged(PhidgetMotorVelocityControllerHandle ch, int engaged) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return (bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETENGAGED, NULL, NULL, 1, "%d", engaged));
}

API_PRETURN
PhidgetMotorVelocityController_getEngaged(PhidgetMotorVelocityControllerHandle ch, int *engaged) {

	TESTPTR_PR(ch);
	TESTPTR_PR(engaged);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*engaged = ch->engaged;
	if (ch->engaged == (int)PUNK_BOOL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMinFailsafeTime(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *minFailsafeTime) {

	TESTPTR_PR(ch);
	TESTPTR_PR(minFailsafeTime);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*minFailsafeTime = ch->minFailsafeTime;
	if (ch->minFailsafeTime == (uint32_t)PUNK_UINT32)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMaxFailsafeTime(PhidgetMotorVelocityControllerHandle ch,
  uint32_t *maxFailsafeTime) {

	TESTPTR_PR(ch);
	TESTPTR_PR(maxFailsafeTime);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*maxFailsafeTime = ch->maxFailsafeTime;
	if (ch->maxFailsafeTime == (uint32_t)PUNK_UINT32)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setMotorInductance(PhidgetMotorVelocityControllerHandle ch,
  double motorInductance) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return (bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETMOTORINDUCTANCE, NULL, NULL, 1, "%g",
	  motorInductance));
}

API_PRETURN
PhidgetMotorVelocityController_getMotorInductance(PhidgetMotorVelocityControllerHandle ch,
  double *motorInductance) {

	TESTPTR_PR(ch);
	TESTPTR_PR(motorInductance);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*motorInductance = ch->motorInductance;
	if (ch->motorInductance == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMinMotorInductance(PhidgetMotorVelocityControllerHandle ch,
  double *minMotorInductance) {

	TESTPTR_PR(ch);
	TESTPTR_PR(minMotorInductance);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*minMotorInductance = ch->minMotorInductance;
	if (ch->minMotorInductance == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getMaxMotorInductance(PhidgetMotorVelocityControllerHandle ch,
  double *maxMotorInductance) {

	TESTPTR_PR(ch);
	TESTPTR_PR(maxMotorInductance);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*maxMotorInductance = ch->maxMotorInductance;
	if (ch->maxMotorInductance == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setMotorPositionType(PhidgetMotorVelocityControllerHandle ch,
  Phidget_MotorPositionType motorPositionType) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return (bridgeSendToDevice((PhidgetChannelHandle)ch, BP_MOTORPOSITIONTYPE, NULL, NULL, 1, "%d",
	  motorPositionType));
}

API_PRETURN
PhidgetMotorVelocityController_getMotorPositionType(PhidgetMotorVelocityControllerHandle ch,
  Phidget_MotorPositionType *motorPositionType) {

	TESTPTR_PR(ch);
	TESTPTR_PR(motorPositionType);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*motorPositionType = ch->motorPositionType;
	if (ch->motorPositionType == (Phidget_MotorPositionType)PUNK_ENUM)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_getRescaleFactor(PhidgetMotorVelocityControllerHandle ch,
  double *rescaleFactor) {

	TESTPTR_PR(ch);
	TESTPTR_PR(rescaleFactor);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*rescaleFactor = ch->rescaleFactor;
	if (ch->rescaleFactor == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setTargetBrakingStrength(PhidgetMotorVelocityControllerHandle ch,
  double targetBrakingStrength) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	return (bridgeSendToDevice((PhidgetChannelHandle)ch, BP_SETBRAKINGDUTYCYCLE, NULL, NULL, 1, "%g",
	  targetBrakingStrength));
}

API_PRETURN
PhidgetMotorVelocityController_getTargetBrakingStrength(PhidgetMotorVelocityControllerHandle ch,
  double *targetBrakingStrength) {

	TESTPTR_PR(ch);
	TESTPTR_PR(targetBrakingStrength);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);
	TESTATTACHED_PR(ch);

	*targetBrakingStrength = ch->targetBrakingStrength;
	if (ch->targetBrakingStrength == (double)PUNK_DBL)
		return (PHID_RETURN(EPHIDGET_UNKNOWNVAL));
	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setOnDutyCycleUpdateHandler(PhidgetMotorVelocityControllerHandle ch,
  PhidgetMotorVelocityController_OnDutyCycleUpdateCallback fptr, void *ctx) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);

	ch->DutyCycleUpdate = fptr;
	ch->DutyCycleUpdateCtx = ctx;

	return (EPHIDGET_OK);
}

API_PRETURN
PhidgetMotorVelocityController_setOnVelocityChangeHandler(PhidgetMotorVelocityControllerHandle ch,
  PhidgetMotorVelocityController_OnVelocityChangeCallback fptr, void *ctx) {

	TESTPTR_PR(ch);
	TESTCHANNELCLASS_PR(ch, PHIDCHCLASS_MOTORVELOCITYCONTROLLER);

	ch->VelocityChange = fptr;
	ch->VelocityChangeCtx = ctx;

	return (EPHIDGET_OK);
}
