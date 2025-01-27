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

#include "Inflate.hpp"

namespace ktl {
	//
	// CreateNativeClassInflate
	//
#define TJS_NATIVE_CLASSID_NAME InflateClassID
	SPRIG_KRKR_BEGIN_CREATE_NATIVE_CLASS(CreateNativeClassInflate, Inflate, Inflate)
	//
	//	SUMMARY: 圧縮レベル系フラグ
	//
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(clfNoCompression, Inflate::clfNoCompression);
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(clfBestSpeed, Inflate::clfBestSpeed);
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(clfBestCompression, Inflate::clfBestCompression);
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(clfDefaultCompression, Inflate::clfDefaultCompression);
	//
	//	SUMMARY: 圧縮メソッド系フラグ
	//
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(cmfDeflated, Inflate::cmfDeflated);
	//
	//	SUMMARY: 圧縮ストラテジー系フラグ
	//
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(csfDefaultStrategy, Inflate::csfDefaultStrategy);
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(csfFiltered, Inflate::csfFiltered);
	SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(csfHuffmanOnly, Inflate::csfHuffmanOnly);
	//
	//	SUMMARY: セットアップ系メソッド
	//
	SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VOID(Inflate, reset);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(Inflate, setup);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(Inflate, setupCompleted, setupCompleted);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(Inflate, finish);
	SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(Inflate, flush);
	//
	//	SUMMARY: パラメータ系メソッド
	//
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, level, getLevel, setLevel);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, method, getMethod, setMethod);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, windowBits, getWindowBits, setWindowBits);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, memLevel, getMemLevel, setMemLevel);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, strategy, getStrategy, setStrategy);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, noHeader, getNoHeader, setNoHeader);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(Inflate, calculateCRC, getCalculateCRC, setCalculateCRC);
	//
	//	SUMMARY: プロパティ系メソッド
	//
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(Inflate, CRC, CRC);
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(Inflate, originalSize, originalSize);
	//
	//	SUMMARY: 処理系メソッド
	//
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(processBlock)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		SPRIG_KRKR_NUMPARAMS_CHECK(2);
		SPRIG_KRKR_TYPE_CHECK(0, tvtInteger);
		SPRIG_KRKR_TYPE_CHECK(1, tvtInteger);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->processBlock(SPRIG_KRKR_ARG_VARIANT(0), SPRIG_KRKR_ARG_VARIANT(1))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(processBlock);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(processBytes)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		SPRIG_KRKR_NUMPARAMS_CHECK(2);
		SPRIG_KRKR_TYPE_CHECK(0, tvtInteger);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->processBytes(SPRIG_KRKR_ARG_VARIANT(0), SPRIG_KRKR_ARG_VARIANT(1))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(processBytes);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(processByte)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		SPRIG_KRKR_NUMPARAMS_CHECK(1);
		SPRIG_KRKR_INVOKE_RESULT_SET(
			this_->processByte(SPRIG_KRKR_ARG_VARIANT(0))
			);
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(processByte);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(processOctet)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		SPRIG_KRKR_NUMPARAMS_EASY_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtOctet);
		if (numparams >= 3) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(1, 3);
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->processOctet(SPRIG_KRKR_ARG_OCTET(0), SPRIG_KRKR_ARG_VARIANT(1), SPRIG_KRKR_ARG_VARIANT(2))
				);
		} else if (numparams >= 2) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(1, 2);
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->processOctet(SPRIG_KRKR_ARG_OCTET(0), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else {
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->processOctet(SPRIG_KRKR_ARG_OCTET(0))
				);
		}
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(processOctet);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(processStorage)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		SPRIG_KRKR_NUMPARAMS_EASY_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		if (numparams >= 3) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(1, 3);
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->processStorage(SPRIG_KRKR_ARG_STRING(0), SPRIG_KRKR_ARG_VARIANT(1), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else if (numparams >= 2) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(1, 2);
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->processStorage(SPRIG_KRKR_ARG_STRING(0), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else {
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->processStorage(SPRIG_KRKR_ARG_STRING(0))
				);
		}
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(processStorage);
	//
	//	SUMMARY: 取得系メソッド
	//
	SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(Inflate, size, size);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(asOctet)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		if (numparams >= 2) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(0, 2);
			SPRIG_KRKR_RESULT_SET(
				this_->asOctet(SPRIG_KRKR_ARG_VARIANT(0), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else if (numparams >= 1) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(0, 1);
			SPRIG_KRKR_RESULT_SET(
				this_->asOctet(SPRIG_KRKR_ARG_VARIANT(0))
				);
		} else {
			SPRIG_KRKR_RESULT_SET(
				this_->asOctet()
				);
		}
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(asOctet);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(asString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		if (numparams >= 2) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(0, 2);
			SPRIG_KRKR_RESULT_SET(
				this_->asString(SPRIG_KRKR_ARG_VARIANT(0), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else if (numparams >= 1) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(0, 1);
			SPRIG_KRKR_RESULT_SET(
				this_->asString(SPRIG_KRKR_ARG_VARIANT(0))
				);
		} else {
			SPRIG_KRKR_RESULT_SET(
				this_->asString()
				);
		}
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(asString);
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(asNarrowString)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		if (numparams >= 2) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(0, 2);
			SPRIG_KRKR_RESULT_SET(
				this_->asNarrowString(SPRIG_KRKR_ARG_VARIANT(0), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else if (numparams >= 1) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(0, 1);
			SPRIG_KRKR_RESULT_SET(
				this_->asNarrowString(SPRIG_KRKR_ARG_VARIANT(0))
				);
		} else {
			SPRIG_KRKR_RESULT_SET(
				this_->asNarrowString()
				);
		}
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(asNarrowString);
	//
	//	SUMMARY: ストレージ系メソッド
	//
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(saveStorage)
	{
		TJS_GET_NATIVE_INSTANCE(this_, Inflate);
		SPRIG_KRKR_NUMPARAMS_EASY_CHECK(1);
		SPRIG_KRKR_TYPE_CHECK(0, tvtString);
		if (numparams >= 3) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(1, 3);
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->saveStorage(SPRIG_KRKR_ARG_STRING(0), SPRIG_KRKR_ARG_VARIANT(1), SPRIG_KRKR_ARG_VARIANT(2))
				);
		} else if (numparams >= 2) {
			SPRIG_KRKR_NUMPARAMS_CHECK_FOR(1, 2);
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->saveStorage(SPRIG_KRKR_ARG_STRING(0), SPRIG_KRKR_ARG_VARIANT(1))
				);
		} else {
			SPRIG_KRKR_INVOKE_RESULT_SET(
				this_->saveStorage(SPRIG_KRKR_ARG_STRING(0))
				);
		}
		return TJS_S_OK;
	}
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(saveStorage);

	SPRIG_KRKR_END_CREATE_NATIVE_CLASS();
#undef TJS_NATIVE_CLASSID_NAME
}	// namespace ktl

//
// regist_ktl_inflate
// unregist_ktl_inflate
//
static void regist_ktl_inflate() {
	SPRIG_KRKR_SECTION(SPRIG_KRKR_TJS_W("KTL:Inflate:regist"), SPRIG_KRKR_LOG_LEVEL_NOTIFICATION);
	sprig::krkr::tjs::object_type global(::TVPGetScriptDispatch(), false);
	if (global) {
		sprig::krkr::tjs::AddNewMember(global, SPRIG_KRKR_TJS_W("Inflate"), ktl::CreateNativeClassInflate());
	}
}
static void unregist_ktl_inflate() {
	SPRIG_KRKR_SECTION(SPRIG_KRKR_TJS_W("KTL:Inflate:unregist"), SPRIG_KRKR_LOG_LEVEL_NOTIFICATION);
	sprig::krkr::tjs::object_type global(::TVPGetScriptDispatch(), false);
	if (global) {
		sprig::krkr::tjs::DeleteMember(global, SPRIG_KRKR_TJS_W("Inflate"));
	}
}
NCB_POST_REGIST_CALLBACK(regist_ktl_inflate);
NCB_PRE_UNREGIST_CALLBACK(unregist_ktl_inflate);

//
// information
//
KTL_INFORMATION(SPRIG_KRKR_TJS_W("KTL:Inflate:information"));
