// /guanwai/laolongtou.c
inherit ROOM;

void create()
{
	set("short", "老龍頭");
	set("long", @LONG
老龍頭是萬裏長城最東端。澄海樓巍峨高踞城頭上，樓上“雄襟萬
裏”的橫匾居高臨下，直俯大海。自澄海樓築有一石城逐級而下伸入大
海，站在石城終端樓平臺上四眺，海天一色，無邊無際，氣象萬千。
LONG );
	set("exits", ([
		"northwest" : __DIR__"shanhaiguan",
		"southwest" : "/d/beijing/road3",
	]));
	set("objects",([
		__DIR__"npc/fengxifan" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 5100);
	set("coor/y", 4500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
