// liufudating.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
        set("short", "劉府大廳");
        set("long", @LONG
劉府大廳裏就安靜多了。主人坐在太師椅上，神色抑鬱。旁邊坐着
一個黑衣老人，神情顯得極爲關切。老人膝上靠着一個小女孩。大廳正
中放着一張茶几，上面鋪了錦緞。一隻金光燦爛、徑長尺半的黃金盆子，
放在茶几之上，盆中已盛滿了清水。
LONG);
        set("exits", ([
            "west"   : __DIR__"liufuwest",
            "east"   : __DIR__"liufueast",
            "south"  : __DIR__"liufudayuan",
            "north"  : __DIR__"shanting",
        ]));
        set("objects", ([
                CLASS_D("henshan")+"/liu":1,
                __DIR__"npc/qu" : 1,
                __DIR__"npc/xiaoqu" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
