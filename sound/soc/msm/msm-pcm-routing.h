/* Copyright (c) 2011-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef _MSM_PCM_ROUTING_H
#define _MSM_PCM_ROUTING_H
#include <sound/apr_audio.h>

#define LPASS_BE_PRI_I2S_RX "(Backend) PRIMARY_I2S_RX"
#define LPASS_BE_PRI_I2S_TX "(Backend) PRIMARY_I2S_TX"
#define LPASS_BE_SLIMBUS_0_RX "(Backend) SLIMBUS_0_RX"
#define LPASS_BE_SLIMBUS_0_TX "(Backend) SLIMBUS_0_TX"
#define LPASS_BE_HDMI "(Backend) HDMI"
#define LPASS_BE_INT_BT_SCO_RX "(Backend) INT_BT_SCO_RX"
#define LPASS_BE_INT_BT_SCO_TX "(Backend) INT_BT_SCO_TX"
#define LPASS_BE_INT_FM_RX "(Backend) INT_FM_RX"
#define LPASS_BE_INT_FM_TX "(Backend) INT_FM_TX"
#define LPASS_BE_AFE_PCM_RX "(Backend) RT_PROXY_DAI_001_RX"
#define LPASS_BE_AFE_PCM_TX "(Backend) RT_PROXY_DAI_002_TX"
#define LPASS_BE_AUXPCM_RX "(Backend) AUX_PCM_RX"
#define LPASS_BE_AUXPCM_TX "(Backend) AUX_PCM_TX"
#define LPASS_BE_VOICE_PLAYBACK_TX "(Backend) VOICE_PLAYBACK_TX"
#define LPASS_BE_INCALL_RECORD_RX "(Backend) INCALL_RECORD_TX"
#define LPASS_BE_INCALL_RECORD_TX "(Backend) INCALL_RECORD_RX"
#define LPASS_BE_SEC_I2S_RX "(Backend) SECONDARY_I2S_RX"

#define LPASS_BE_MI2S_RX "(Backend) MI2S_RX"
#define LPASS_BE_MI2S_TX "(Backend) MI2S_TX"
#define LPASS_BE_STUB_RX "(Backend) STUB_RX"
#define LPASS_BE_STUB_TX "(Backend) STUB_TX"
/* For multimedia front-ends, asm session is allocated dynamically.
 * Hence, asm session/multimedia front-end mapping has to be maintained.
 * Due to this reason, additional multimedia front-end must be placed before
 * non-multimedia front-ends.
 */

enum {
	MSM_FRONTEND_DAI_MULTIMEDIA1 = 0,
	MSM_FRONTEND_DAI_MULTIMEDIA2,
	MSM_FRONTEND_DAI_MULTIMEDIA3,
	MSM_FRONTEND_DAI_MULTIMEDIA4,
	MSM_FRONTEND_DAI_CS_VOICE,
	MSM_FRONTEND_DAI_VOIP,
	MSM_FRONTEND_DAI_AFE_RX,
	MSM_FRONTEND_DAI_AFE_TX,
	MSM_FRONTEND_DAI_VOICE_STUB,
	MSM_FRONTEND_DAI_VOLTE,
	MSM_FRONTEND_DAI_MAX,
};

#define MSM_FRONTEND_DAI_MM_SIZE (MSM_FRONTEND_DAI_MULTIMEDIA4 + 1)
#define MSM_FRONTEND_DAI_MM_MAX_ID MSM_FRONTEND_DAI_MULTIMEDIA4

enum {
	MSM_BACKEND_DAI_PRI_I2S_RX = 0,
	MSM_BACKEND_DAI_PRI_I2S_TX,
	MSM_BACKEND_DAI_SLIMBUS_0_RX,
	MSM_BACKEND_DAI_SLIMBUS_0_TX,
	MSM_BACKEND_DAI_HDMI_RX,
	MSM_BACKEND_DAI_INT_BT_SCO_RX,
	MSM_BACKEND_DAI_INT_BT_SCO_TX,
	MSM_BACKEND_DAI_INT_FM_RX,
	MSM_BACKEND_DAI_INT_FM_TX,
	MSM_BACKEND_DAI_AFE_PCM_RX,
	MSM_BACKEND_DAI_AFE_PCM_TX,
	MSM_BACKEND_DAI_AUXPCM_RX,
	MSM_BACKEND_DAI_AUXPCM_TX,
	MSM_BACKEND_DAI_VOICE_PLAYBACK_TX,
	MSM_BACKEND_DAI_INCALL_RECORD_RX,
	MSM_BACKEND_DAI_INCALL_RECORD_TX,
	MSM_BACKEND_DAI_MI2S_RX,
	MSM_BACKEND_DAI_MI2S_TX,
	MSM_BACKEND_DAI_SEC_I2S_RX,
	MSM_BACKEND_DAI_MAX,
};

struct msm_pcm_routing_ops {
	int (*get_q6_effect) (void);
};

/* dai_id: front-end ID,
 * dspst_id:  DSP audio stream ID
 * stream_type: playback or capture
 */
void msm_pcm_routing_reg_phy_stream(int fedai_id, int dspst_id,
	int stream_type);
void msm_pcm_routing_reg_psthr_stream(int fedai_id, int dspst_id,
		int stream_type, int enable);

void msm_pcm_routing_dereg_phy_stream(int fedai_id, int stream_type);

int msm_pcm_routing_get_port(struct snd_pcm_substream *substream);

int lpa_set_volume(unsigned volume);

int compr_set_volume(unsigned volume);

int multi_ch_pcm_set_volume(unsigned volume);

int msm_routing_check_backend_enabled(int fedai_id);

void htc_8960_register_pcm_routing_ops(struct msm_pcm_routing_ops *ops);
#endif /*_MSM_PCM_H*/
