// Room: /d/nanshaolin/qdian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
void create()
{
	set("short", "前殿");
	set("long", @LONG
這裏是天王殿前的一處前殿。規模很小，殿內亦無很多擺設。只有
幾個小沙禰在接待着來往的香客。透過洞開的大門，可以看到前面規模
雄偉的天王殿。
LONG );
	set("exits", ([
		"south" : __DIR__"gchang-1",
                "north" : __DIR__"twdian",
	]));
	set("objects",([
                CLASS_D("nanshaolin") + "/yuanshang" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

