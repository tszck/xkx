// Room: /d/nanshaolin/zhlou3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓三層");
	set("long", @LONG
塔身往上似乎越來越窄，樓梯也漸為擠仄。扶手上不少朽壞處續接
了新木，漆色也是新舊不同。從窗孔往外望，往北可以看到竹林中的藏
經樓和方丈樓露出飛檐一角，往西則是前殿的屋頂，屋脊上塑了個大大
的“佛”字。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou4",
		"down" : __DIR__"zhlou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

