// Room: /city/lichunyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "麗春院");
	set("long", @LONG
你一走進來，一眼就看到大廳的牆上掛着一幅幅春宮圖(tu)，一下
子就明白了這是什麼地方。廳內到處張燈結綵，香氣撲鼻。幾名打扮得
妖裏妖氣的女人分站兩旁對你發出媚笑。主人韋春芳上上下下、前前後
後招呼着客人。從樓上傳來了陣陣打情罵俏的聲音。
LONG );
	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
                "/d/beijing/npc/mao18" : 1, 
	]));

	set("item_desc", ([
		"tu" :
"                                      Ο        Ο          Ο             
                                    ┌│        │          │
      ┌—Ο┌—  —┬——Ο        │┤      ┌┘          └┐
    —┘Ο—┘    ————Ο  Ο——┘│  Ο—┼┴—  Ο——┴┼


   Ο       Ο    ΟΟΟ                 Ο                  ○
   │       │    │├┼       ┌—Ο  ┌┼                  │
   ├ Ο┬┐┤    ├└┼┐   —┘Ο——┘┤          ○┬—┐┤
   │   ┘└│    │  │                 └            │  ││
	\n"]));
	set("exits", ([
		"east"  : __DIR__"beiliuxiang",
		"up"    : __DIR__"lichunyuan2",
	]));

	set("coor/x", 30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
