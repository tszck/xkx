// Room: nanyan0.c 南巖宮地下室
// Date: Oct.5 1997
#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "南巖宮地下室");
        set("long", @LONG
這是一個乾燥潔淨的地下室，四壁用光滑的大理石砌就，十數支松
明照得這裏通明透亮。
LONG );
        set("objects", ([
           CLASS_D("wudang") +"/xiaosong": 1,
        ]));

        set("exits", ([
//              "up"     : __DIR__"nanyangong",
                "east"   : __DIR__"nanyan1",
                "west"   : __DIR__"nanyan2",
                "south"  : __DIR__"nanyan3",
                "north"  : __DIR__"nanyan4",
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -2040);
	set("coor/y", -960);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	string fskill;
    if ( dir == "up" )
    {
    	fskill = me->query_skill_mapped("force");
       if ( !fskill || me->query_skill(fskill, 1) < 80 )
          {
              return notify_fail("你試着推了推頂上的磚蓋，觸手冰涼，紋絲不動。\n"
              + "哈哈，你完蛋了。\n");
          }
          message_vision( HIY
            "$N全身運足"+to_chinese(fskill)+"，拔身錯步，嘿地一聲，舉起雙掌向上猛擊。只見\n"
            "一股白氣自$N掌心而出，迅猛無比地擊中頂上的磚蓋。克剌剌一聲\n"
            "巨響，磚蓋被震成無數小碎片四散飄飛。露出一個向上的洞口來。\n" NOR, me );
       me->move(__DIR__"nanyangong");
       return notify_fail("");
     }
     return ::valid_leave(me, dir);
}
