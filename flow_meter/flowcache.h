/**
 * \file flowcache.h
 * \brief Generic flow cache interface (FlowCache class)
 * \author Vaclav Bartos <bartos@cesnet.cz>
 * \author Jiri Havranek <havraji6@fit.cvut.cz>
 * \date 2014
 * \date 2015
 */
/*
 * Copyright (C) 2014-2015 CESNET
 *
 * LICENSE TERMS
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is'', and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */

#ifndef FLOWCACHE_H
#define FLOWCACHE_H

#include "packet.h"
#include "flowifc.h"
#include "flowcacheplugin.h"
#include "flowexporter.h"

#include <vector>
#include <cstring>

/**
 * \brief Base class for flow caches.
 */
class FlowCache
{
protected:
   FlowExporter *exporter; /**< Instance of FlowExporter used to export flows. */
private:
   std::vector<FlowCachePlugin *> plugins; /**< Array of plugins. */

public:
   /**
    * \brief Put packet into the cache (i.e. update corresponding flow record or create a new one)
    * \param [in] pkt Input parsed packet.
    * \return 0 on success.
    */
   virtual int put_pkt(Packet &pkt) = 0;

   /**
    * \brief Initialize flow cache.
    * Should be called before first call of recv_pkt, after all plugins are added.
    */
   virtual void init()
   {
      plugins_init();
   }

   /**
    * \brief Cleanup function.
    * Should be called after last call of recv_pkt.
    */
   virtual void finish()
   {
      plugins_finish();
   }

   /**
    * \brief Set an instance of FlowExporter used to export flows.
    */
   void set_exporter(FlowExporter *exp)
   {
      exporter = exp;
   }

   /**
    * \brief Add plugin to internal list of plugins.
    * Plugins are always called in the same order, as they were added.
    */
   void add_plugin(FlowCachePlugin *plugin)
   {
      plugins.push_back(plugin);
   }

protected:
   //Every FlowCache implementation should call these functions at appropriate places

   /**
    * \brief Initialize added plugins.
    */
   void plugins_init()
   {
      for (unsigned int i = 0; i < plugins.size(); i++) {
         plugins[i]->init();
      }
   }

   /**
    * \brief Call post_create function for each added plugin.
    * \param [in,out] rec Stored flow record.
    * \param [in] pkt Input parsed packet.
    * \return Options for flow cache.
    */
   int plugins_post_create(FlowRecord &rec, const Packet &pkt)
   {
      int retval = 0;
      for (unsigned int i = 0; i < plugins.size(); i++) {
         int tmp = plugins[i]->post_create(rec, pkt);
         if (tmp != 0) {
            retval |= tmp;
         }
      }
      return retval;
   }

   /**
    * \brief Call pre_update function for each added plugin.
    * \param [in,out] rec Stored flow record.
    * \param [in] pkt Input parsed packet.
    * \return Options for flow cache.
    */
   int plugins_pre_update(FlowRecord &rec, Packet &pkt)
   {
      int retval = 0;
      for (unsigned int i = 0; i < plugins.size(); i++) {
         int tmp = plugins[i]->pre_update(rec, pkt);
         if (tmp != 0) {
            retval |= tmp;
         }
      }
      return retval;
   }

   /**
    * \brief Call post_update function for each added plugin.
    * \param [in,out] rec Stored flow record.
    * \param [in] pkt Input parsed packet.
    */
   void plugins_post_update(FlowRecord &rec, const Packet &pkt)
   {
      for (unsigned int i = 0; i < plugins.size(); i++) {
         plugins[i]->post_update(rec, pkt);
      }
   }

   /**
    * \brief Call pre_export function for each added plugin.
    * \param [in,out] rec Stored flow record.
    */
   void plugins_pre_export(FlowRecord &rec)
   {
      for (unsigned int i = 0; i < plugins.size(); i++) {
         plugins[i]->pre_export(rec);
      }
   }

   /**
    * \brief Call finish function for each added plugin.
    */
   void plugins_finish()
   {
      for (unsigned int i = 0; i < plugins.size(); i++) {
         plugins[i]->finish();
      }
   }
};

#endif