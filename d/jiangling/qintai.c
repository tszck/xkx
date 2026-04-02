//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "古琴臺");
	set ("long", @LONG
這裏又名伯牙臺。相傳春秋戰國時期，楚國琴師俞伯牙路經漢陽，
夜泊江岸，當晚雨後月朗天清，伯牙撫琴抒懷，樵夫鍾子期路過，聽罷
一曲《高山流水》，情不自禁讚道：“峨峨兮若泰山，洋洋兮若江河”。
伯牙巧遇知音，大爲高興。兩人相約半年後來此一聚。第二年，子期不
幸病逝，伯牙悲痛欲絕，來到子期墓前，重彈《高山流水》，並將七絃
琴摔碎，長歌痛哭。後人爲了紀念這個“摔琴謝知音”的故事，建了這
個琴臺。琴臺中央石碑上刻有伯牙半身像。北面有一座飛檐高聳的亭子。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"north" : __DIR__"qinguan",
		"west"  : __DIR__"hzjie3",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
