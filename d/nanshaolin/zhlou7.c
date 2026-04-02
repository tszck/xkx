// Room: /d/nanshaolin/zhlou7.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓七層");
	set("long", @LONG
這裏就是鐘樓之頂。直入眼簾的便是那口大鐘和一根懸掛空中的巨
杵。細看大鐘，整整有兩丈來高，直徑也有丈許。鐘身似由青銅澆鑄，
上面滿是密密麻麻的印文古篆，估計重逾數千斤。巨杵粗可合抱，丈把
來長，一頭裹以厚皮，正對着鐘腰。
LONG );
	set("exits", ([
		"down" : __DIR__"zhlou6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

