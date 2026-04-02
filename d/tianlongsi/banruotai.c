inherit ROOM;

void create()
{
        set("short", "般若臺");
        set("long",@LONG
這是個普通的石臺，相傳當年佛祖曾降臨此臺傳法。再往南去就是本
寺重地——牟尼堂。江湖中傳言天龍寺的鎮寺之寶——六脈神劍譜就藏於
此中，但你千萬不要打什麼主意。
LONG );
	set("exits", ([
		"south" : __DIR__"munitang",
		"north" : __DIR__"doushuai",
	]));
	set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}