# pyOCD debugger
# Copyright (c) 2026 Kai
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ...coresight.coresight_target import CoreSightTarget
from ...core.memory_map import FlashRegion, MemoryMap, RamRegion
from ...flash.flash import Flash


class DBGMCU:
    # DBGMCU APB freeze @ 0x4000580C
    APB = 0x4000580C
    # TMR1/2/3/4 | LPTMR | RTC | WWDT | IWDT
    APB_VALUE = 0x00039071


FLASH_ALGO = {
    'load_address': 0x20000000,
    'instructions': [
        0xe7fdbe00,
        0xd3022820, 0x1d000940, 0x28104770, 0x0900d302, 0x47701cc0, 0x47700880, 0x48722101, 0x60810449,
        0x618121ff, 0x47702000, 0x4d6fb578, 0x95004b6d, 0x210c68d8, 0x60d84308, 0x240168d8, 0x60d84320,
        0x0419486a, 0x496a6008, 0xe0044a6a, 0x98006011, 0x96001e46, 0x6898d309, 0xd4f70740, 0xe0069500,
        0x98006011, 0x95001e45, 0x2001d201, 0x6898bd78, 0xd0f507c0, 0x2000609c, 0xb578bd78, 0x06c9211f,
        0x4d594a5d, 0x95001841, 0xd3014291, 0xbd782000, 0x68d14a54, 0x4399230c, 0x68d160d1, 0x43192301,
        0x495260d1, 0x49526001, 0xe0044c52, 0x98006021, 0x96001e46, 0x6890d309, 0xd4f70740, 0xe0069500,
        0x98006021, 0x95001e45, 0x2001d201, 0x6890bd78, 0xd0f507c0, 0xe7d96093, 0x4b43b5f8, 0x231f9300,
        0x06db0889, 0x00894c44, 0x4d4118c3, 0x4f3d4e41, 0xd20342a3, 0xca08e02f, 0x1f09c008, 0xd1fa2900,
        0x68fbe02b, 0x43232402, 0x681360fb, 0x4b366003, 0xe0049300, 0x9b006035, 0x94001e5c, 0x68bbd311,
        0xd4f7075b, 0x069b68bb, 0xd0020f5b, 0x60b82038, 0x4b2de007, 0xe0069300, 0x9b006035, 0x94001e5c,
        0x2001d201, 0x68bbbdf8, 0xd5f5079b, 0x60bb2302, 0x1f091d00, 0x29001d12, 0x2000d1d3, 0xb538bdf8,
        0x49204c21, 0x6a089400, 0x05c04a22, 0x4823d405, 0x20066010, 0x48226050, 0x6a086090, 0x28aab2c0,
        0x4820d022, 0x48206048, 0x4b196048, 0x6013e004, 0x1e459800, 0xd3109500, 0x03406888, 0x481bd5f7,
        0x6a886288, 0x062d2501, 0x62884328, 0xe0069400, 0x98006013, 0x94001e44, 0x2001d201, 0x6a88bd38,
        0xd4f501c0, 0x60c84812, 0x04802001, 0x48116088, 0x48116008, 0x20386008, 0x20076088, 0x20006188,
        0x0000bd38, 0x40020800, 0x0007a120, 0x0000a5a5, 0x0000aaaa, 0x40002400, 0x00020001, 0x00005555,
        0x00000fff, 0xaaaabbbb, 0x44556677, 0x00ff83aa, 0xa5a58000, 0x96969696, 0x3c3c3c3c, 0x00000000,
    ],
    'pc_init': 0x20000163,
    'pc_unInit': 0x2000001d,
    'pc_program_page': 0x200000dd,
    'pc_erase_sector': 0x2000007f,
    'pc_eraseAll': 0x2000002d,
    'static_base': 0x20000000 + 0x00000004 + 0x21c,
    'begin_stack': 0x20001630,
    'end_stack': 0x20000630,
    'page_size': 0x200,
    'analyzer_supported': False,
    'analyzer_address': 0x0,
    'page_buffers': [0x20000230, 0x20000430],
    'min_program_length': 0x200,
    'ro_start': 0x4,
    'ro_size': 0x21c,
    'rw_start': 0x220,
    'rw_size': 0x4,
    'zi_start': 0x224,
    'zi_size': 0x0,
    'flash_start': 0x8000000,
    'flash_size': 0x20000,
    'sector_sizes': (
        (0x0, 0x200),
    ),
}

OPT_ALGO = {
    'load_address': 0x20000000,
    'instructions': [
        0xe7fdbe00,
        0x4827b518, 0x90004b27, 0x4c276a18, 0xd40505c0, 0x60204826, 0x60602006, 0x60a04825, 0x60584825,
        0x60584825, 0xe0064925, 0x98006021, 0x92001e42, 0x2001d201, 0x6898bd18, 0xd5f50340, 0xbd182000,
        0x49182001, 0x60880480, 0x47702000, 0x47702000, 0x47702000, 0x4812b538, 0x79109000, 0x04057893,
        0x78140718, 0x7a110d00, 0x7a924305, 0x4b0d4325, 0x43080210, 0x62d8629d, 0x21016a98, 0x43080609,
        0x490e6298, 0xe0064c08, 0x98006021, 0x92001e42, 0x2001d201, 0x6a98bd38, 0xd4f501c0, 0xbd382000,
        0x0007a120, 0x40020800, 0x40002400, 0x00005555, 0x00000fff, 0xaaaabbbb, 0x44556677, 0x0000aaaa,
        0x00000000
    ],
    'pc_init': 0x20000005,
    'pc_unInit': 0x20000045,
    'pc_program_page': 0x20000059,
    'pc_erase_sector': 0x20000055,
    'pc_eraseAll': 0x20000051,
    'static_base': 0x20000000 + 0x00000004 + 0x000000c0,
    'begin_stack': 0x200010e8,
    'end_stack': 0x200000e8,
    'page_size': 0xc,
    'analyzer_supported': False,
    'analyzer_address': 0x00000000,
    'page_buffers': [0x200000d0, 0x200000dc],
    'min_program_length': 0xc,
    'ro_start': 0x4,
    'ro_size': 0xc0,
    'rw_start': 0xc4,
    'rw_size': 0x4,
    'zi_start': 0xc8,
    'zi_size': 0x0,
    'flash_start': 0x1fff0000,
    'flash_size': 0xc,
    'sector_sizes': (
        (0x0, 0xc),
    ),
}


class G32R430Flash(Flash):
    def prepare_target(self):
        # Match pyocd load / MDK: clean reset before FLM in RAM.
        # Commander erase otherwise leaves app state and EraseChip HardFaults (IPSR=3).
        self.target.reset_and_halt()
        self.target.write32(DBGMCU.APB, DBGMCU.APB_VALUE)


class G32R430xB(CoreSightTarget):
    VENDOR = "Geehy"

    MEMORY_MAP = MemoryMap(
        FlashRegion(
            start=0x08000000,
            length=0x20000,
            sector_size=0x200,
            page_size=0x200,
            is_boot_memory=True,
            algo=FLASH_ALGO,
            flash_class=G32R430Flash,
        ),
        FlashRegion(
            start=0x1FFF0000,
            length=0xC,
            sector_size=0xC,
            page_size=0xC,
            algo=OPT_ALGO,
            flash_class=G32R430Flash,
        ),
        RamRegion(start=0x20000000, length=0x40000),
    )

    def __init__(self, session):
        super().__init__(session, self.MEMORY_MAP)

    def post_connect_hook(self):
        self.write32(DBGMCU.APB, DBGMCU.APB_VALUE)
