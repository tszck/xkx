inherit ROOM;

void create()
{
	set("short", "戲院後臺");
	set("long", @LONG
這裏是戲院後臺，幾個戲子正在化妝。從北邊可以上臺。
LONG );
	set("exits", ([
  		"west"    : __DIR__"xiyuan",
  		"northup" : __DIR__"stage",
	]));
        set("objects", ([
                __DIR__"npc/xizi" : 2,
        ]));
	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
