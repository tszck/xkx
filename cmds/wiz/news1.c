// news cmds
// by Doing

inherit F_CLEAN_UP;
#include <ansi.h>

string bshort(object board);
int do_look(object board);

int main(object me, string arg)
{
	object board;
	seteuid(getuid());
	board=find_object("/clone/board/news_b");
	if (!board) board=new("/clone/board/news_b");
        if (! arg || arg == "" )
        {
                tell_object(me,bshort(board));
                return 1;
        }
        if (arg == "all")
        {//news all == l board
                return do_look(board);
        }

        if (sscanf(arg, "discard %s", arg))
        {
                return board->delete_post(arg);
        }

        if (sscanf(arg, "post %s", arg))
        {
       		 	if (! wizardp(me) || ! interactive(me))
       			 {
                tell_object(me, "只有巫師才能發佈新聞。\n");
                return 1;
       	 		}
        			if (replace_string(arg, " ", "") == "")
         		       arg = "無標題";
                if (board->do_post(arg))
                 {
         shout(HIC "【俠客行一百】" NOR + WHT + me->name() + WHT "[" +
             me->query("id") + WHT "]發佈了一條新聞，請用(news)命令查看。\n" NOR);

        tell_object(me, HIC "【俠客行一百】" NOR + WHT + me->name() + WHT "[" +
             me->query("id") + WHT "]發佈了一條新聞。\n" NOR);

        tell_object(me, "新聞發佈完成。\n");
                	return 1;
                 	}
                 return 0;
        }

        return board->do_read(arg);
}
string bshort(object board)
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = board->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return " [ 目前沒有任何更新消息 ]\n";

	if( this_player() )
	{
		last_read_time = (int)this_player()->query("board_last_read/" + (string)board->query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )

		return
		sprintf(HIW"俠客行一百總共發佈過"HIY"%s"HIW"條更新消息，其中"HIR"%s"HIW"篇未讀。\n"NOR,chinese_number(sizeof(notes)),chinese_number(unread));
	else
		return sprintf(HIW"俠客行一百總共發佈過"HIY"%s"HIW"條更新消息，目前沒有任何未讀過的消息。\n"NOR, chinese_number(sizeof(notes)));
}

//news all  ==  look board
int do_look(object board)
{
	mapping *notes;
	int i, t, max,size,num,last_time_read;
	string msg/*, myid*/;
	object ob = board;
	object me = this_player();
	notes = ob->query("notes");
	size = (int)sizeof(notes)/20;
	if( !pointerp(notes) || !sizeof(notes) )
	{
		msg="[ 目前沒有任何更新消息 ]\n";
		message("vision", msg, me);
		return 1;
	}

	msg="俠客行一百最近的更新消息如下：\n"
	HIW"編號"NOR"----"HIY"標題"NOR"----------------------------------------"HIR"作者"NOR"--"HIG"回覆數"NOR"------"HIM"時間"NOR"----------"NOR;
	last_time_read = me->query("board_last_read/news_b");
	message("vision", msg, me);
//	for(t=0; t<=size; t++)
    for(t=size;t>=0;t--)
    	{
//    		num = t*20;                0-20  0-62 共63個消息  size=3
        num = (sizeof(notes)-1)-(size-t)*20;      // (24-1)-(1-2)   num=62 42 22 2
//    		max = num + 20;
        max = num-20;          //          max=42 22 2 -18
//    		if( max > sizeof(notes)) max = (int)sizeof(notes);
        if( max <0 ) max = -1;  //         max=42 22 2 -1
    		i=num;                 //         i= 62 42 22 2
      	msg = sprintf("\n%s[%2d]"HIR" %s "HIY"%-29s"HIR" %20s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:HIW), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"]+"("+notes[i]["owner"]+")", sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
      //                 HIR[21]       M     title       qingyun  +0
//                                         msg= post 62 42 22 2
//    		for(i=num+1; i<max; i++)   // note[1]-note[19]  0-19
        for (i=num-1; i>max;i--)     //i=61,43  41,23 21,3  1,0
    		{
//        msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
        msg += sprintf("\n%s[%2d]"HIR" %s "HIY"%-29s"HIR" %20s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:HIW), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"]+"("+notes[i]["owner"]+")", sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    		}
    		message("vision", msg, me);
        }

/*      i = sizeof(notes);
      msg = "";
      while(i--)
          msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    	message("vision", msg, me);
*/        msg = "\n--------------------------------------------------------------------------------------\n";
        msg += sprintf("共有 %d 條消息。\n", sizeof(notes));
    	message("vision", msg, me);
    	return 1;
}
void check_me(object me)
{
	mapping *notes;
	int i, unread, last_read_time;
	object board;
	seteuid(getuid());
	board=find_object("/clone/board/news_b");
	if (!board) board=new("/clone/board/news_b");
	notes = board->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )	return;
	if( me )
	{
		last_read_time = (int)me->query("board_last_read/" + (string)board->query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		{
      if (!me->query_temp("news"))
			tell_object(me,HIY"在你離線期間俠客行一百有過更新消息，請仔細閱讀以下內容。\n\n"NOR);
      me->set_temp("news",1);
      seteuid(ROOT_UID);
      me->force_me("news new");
    }
  if (unread > 1 )
  {
  	remove_call_out("check_me");
  	call_out("check_me",60,me);
  }
}
int help(object me)
{
	write(@HELP
指令格式 : news [next] | [<新聞編號>] | new | all

這條指令讓你你可以閱讀遊戲中的新聞。所有的更新和消息都是通過
新聞發佈的。

使用 new 參數可以讓你閱讀還沒有讀過的新聞。
使用 all 參數可以讓你查看系統目前所有的新聞。

巫師可以通過news post <標題>來發布新聞。
            news discard來刪除自己發佈的新聞。
HELP );
    return 1;
}