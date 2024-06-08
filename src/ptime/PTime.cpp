/*=============================================================================
  Copyright (c) 2010-2015 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/KTL

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#include "Config.hpp"

#include <sprig/external/tp_stub.hpp>
#include <sprig/external/ncbind/ncbind.hpp>
#include <sprig/krkr/tjs.hpp>
#include <sprig/krkr/macro.hpp>
#include <sprig/krkr/ncb.hpp>
#include <ktl/config.hpp>
#include <ktl/information.hpp>

#include "PTime.hpp"

namespace ktl {
	//
	// CreateNativeClassPTime
	//
#define TJS_NATIVE_CLASSID_NAME PTimeClassID
	SPRIG_KRKR_BEGIN_CREATE_NATIVE_CLASS(CreateNativeClassPTime, PTime, PTime)
	//
	//	SUMMARY: 内部系メソッド
	//
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, instance, getInstance);
	//
	//	SUMMARY: 割り当て系メソッド
	//
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(PTime, assignLocalTimeSecondClock);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(PTime, assignUniversalTimeSecondClock);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(PTime, assignLocalTimeMicrosecClock);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(PTime, assignUniversalTimeMicrosecClock);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(PTime, assignLocalTimeDayClock);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(PTime, assignUniversalTimeDayClock);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignDateTime)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignDateTime(
				SPRIG_KRKR_ARG_VARIANT(0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(1, 1),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(2, 1),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(3, 0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(4, 0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(5, 0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(6, 0)
				)
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignDateTime);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignDate)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignDate(
				SPRIG_KRKR_ARG_VARIANT(0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(1, 1),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(2, 1)
				)
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignDate);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignTime)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignTime(
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(0, 0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(1, 0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(2, 0),
				SPRIG_KRKR_ARG_VARIANT_DEFAULT(3, 0)
				)
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignTime);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignFromString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignFromString(SPRIG_KRKR_ARG_STRING(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignFromString);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignFromISOString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignFromISOString(SPRIG_KRKR_ARG_STRING(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignFromISOString);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignDateFromString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignDateFromString(SPRIG_KRKR_ARG_STRING(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignDateFromString);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignDateFromISOString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignDateFromISOString(SPRIG_KRKR_ARG_STRING(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignDateFromISOString);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignTimeFromString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignTimeFromString(SPRIG_KRKR_ARG_STRING(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignTimeFromString);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(assignTimeFromISOString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->assignTimeFromISOString(SPRIG_KRKR_ARG_STRING(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(assignTimeFromISOString);
	//
	//	SUMMARY: 変更系メソッド
	//
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveYears)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveYears(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveYears);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveMonths)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveMonths(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveMonths);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveDays)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveDays(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveDays);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveHours)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveHours(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveHours);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveMinutes)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveMinutes(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveMinutes);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveSeconds)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveSeconds(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveSeconds);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveMilliseconds)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveMilliseconds(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveMilliseconds);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(moveMicroseconds)
	{
		TJS_GET_NATIVE_INSTANCE(this_, PTime);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		this_->moveMicroseconds(SPRIG_KRKR_ARG_VARIANT(0));
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(moveMicroseconds);
	//
	//	SUMMARY: 文字列化系メソッド
	//
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toISOString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toISOExtendedString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toDataString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toDataISOString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toDataISOExtendedString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toTimeString);
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(PTime, toTimeISOString);
	//
	//	SUMMARY: 日付プロパティ系メソッド
	//
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, year, year);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, month, month);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, day, day);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, dayOfYear, dayOfYear);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, dayOfWeek, dayOfWeek);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, weekNumber, weekNumber);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, julianDay, julianDay);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, modjulianDay, modjulianDay);
	//
	//	SUMMARY: 時刻プロパティ系メソッド
	//
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, hours, hours);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, minutes, minutes);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, seconds, seconds);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, totalSeconds, totalSeconds);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, totalMilliseconds, totalMilliseconds);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, totalMicroseconds, totalMicroseconds);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, totalNanoseconds, totalNanoseconds);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, fractionalSeconds, fractionalSeconds);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(PTime, numFractionalDigits, numFractionalDigits);

	SPRIG_KRKR_END_CREATE_NATIVE_CLASS();
#undef TJS_NATIVE_CLASSID_NAME
}	// namespace ktl

//
// regist_ktl_ptime
// unregist_ktl_ptime
//
static void regist_ktl_ptime() {
	SPRIG_KRKR_SECTION(SPRIG_KRKR_TJS_W("KTL:PTime:regist"), SPRIG_KRKR_LOG_LEVEL_NOTIFICATION);
	sprig::krkr::tjs::object_type global(::TVPGetScriptDispatch(), false);
	if (global) {
		sprig::krkr::tjs::AddNewMember(global, SPRIG_KRKR_TJS_W("PTime"), ktl::CreateNativeClassPTime());
	}
}
static void unregist_ktl_ptime() {
	SPRIG_KRKR_SECTION(SPRIG_KRKR_TJS_W("KTL:PTime:unregist"), SPRIG_KRKR_LOG_LEVEL_NOTIFICATION);
	sprig::krkr::tjs::object_type global(::TVPGetScriptDispatch(), false);
	if (global) {
		sprig::krkr::tjs::DeleteMember(global, SPRIG_KRKR_TJS_W("PTime"));
	}
}
NCB_POST_REGIST_CALLBACK(regist_ktl_ptime);
NCB_PRE_UNREGIST_CALLBACK(unregist_ktl_ptime);

//
// information
//
KTL_INFORMATION(SPRIG_KRKR_TJS_W("KTL:PTime:information"));
