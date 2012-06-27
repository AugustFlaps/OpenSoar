/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2012 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#ifndef XCSOAR_NET_DOWNLOAD_MANAGER_HPP
#define XCSOAR_NET_DOWNLOAD_MANAGER_HPP

#include "Net/Features.hpp"
#include "Compiler.h"

#include <tchar.h>

namespace Net {
  class DownloadListener {
  public:
    virtual void OnDownloadComplete(const char *path_relative,
                                    bool success) = 0;
  };
}

namespace Net {
  namespace DownloadManager {
#ifdef HAVE_DOWNLOAD_MANAGER
    bool Initialise();
    void Deinitialise();

    gcc_pure
    bool IsAvailable();

    void AddListener(DownloadListener &listener);
    void RemoveListener(DownloadListener &listener);

    void Enqueue(const char *uri, const TCHAR *relative_path);
#else

    static inline bool IsAvailable() {
      return false;
    }
#endif
  }
}

#endif
