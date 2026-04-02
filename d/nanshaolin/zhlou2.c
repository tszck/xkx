// Room: /d/nanshaolin/zhlou2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓二層");
	set("long", @LONG
每個樓層上都鋪設了結實的木樓板，八角形的牆身上則開了四扇大
窗。從窗孔看，牆體也是極為厚實。從這裏往外眺望，可以看到圍繞塔
周的小園以及北邊的竹林，隨風飄來陣陣竹葉的清香。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou3",
		"down" : __DIR__"zhlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

