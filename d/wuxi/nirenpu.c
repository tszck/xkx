// Room: /d/wuxi/nirenpu.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "泥人鋪");
	set("long", @LONG
    這裏專賣無錫特產－－惠山泥人，櫃檯上擺了好幾排形態各異精
巧傳神的泥人，其中數大小阿福最爲惹人喜愛。張老闆學得一手祖傳
的泥人手藝，所賣的泥人遠近聞名。
LONG );
	set("exits", ([
		"east"  : __DIR__"northroad1",
	]));
	set("objects", ([
			__DIR__"npc/zhang" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}