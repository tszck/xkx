// Room: /d/taohua/sixiang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "四象");
	set("long", @LONG
這裏是四象層，你一走下來，往上的鐵梯就被撤掉了。所謂四象，
係指陰陽變化的四態，亦即太陰、少陽、太陽、少陰，是陰陽互相轉化
的形式。陰極中的陰就是太陰，而陰中帶陽就是少陽，同樣的也有太陽
和少陰。四象進一步演化即是四象生八卦，以方位倒轉八卦論，太陽之
陽爲乾，居正南，太陰之陰爲坤，於正北；少陰之陽爲離，居東方，少
陽之陰爲坎，在西方。四象又對應五靈中的四獸，而此室居中央，表示
五靈中的人統領其餘四靈獸。以方位入五行，此中土之形，尚黃，有一
道鐵梯直通下方的中央戊己土。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"taiyin",
		"south" : __DIR__"taiyang",
		"west" : __DIR__"shaoyang",
		"east" : __DIR__"shaoyin",
		"down" : __DIR__"tu",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("這裏不準存盤！\n");
	return 1;
}

int do_quit()
{
	write("這裏不準退出！\n");
	return 1;
}