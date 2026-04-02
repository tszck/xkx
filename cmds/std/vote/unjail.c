// vote unjail
inherit F_CONDITION;

#include <command.h> 
#include <vote.h> 
#include <ansi.h>
#define JAIL "/d/beijing/jail"



int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string *juror, my_ip , *ips;
  object *inv;

  if (base_name(environment(victim))!= JAIL)
  {
         return notify_fail("你投票的人不在刑部大牢!\n");
  }

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("你不是開玩笑吧？當心被剝奪表決權！\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_CHBLK))
  {
  	return notify_fail("要把當前的表決完成以後纔可以提新的動議。\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_CHBLK); 
  }
  
  my_ip = query_ip_name(me);

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_ip }) );
  } else if( member_array(my_ip, juror) == -1 || wizardp(me)) 
  {
 	victim->set("vote/juror", juror+({ my_ip }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("一人一票！濫用表決權是要受懲罰的！\n");
  }

/*  vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  
  vc = victim->add("vote/count", 1);

  df = (int)((vv - vc)/2);
  if (vv < 4) df = 4 - vc;*/
  ips = ("/cmds/std/vote")->valid_voters(me);
  vv = sizeof(ips);
  for (i=0;i<sizeof(juror);i++)
  {
  	if (member_array(juror[i],ips)==-1)
  	 vc = victim->add("vote/count",-1);
  }
  vc = victim->add("vote/count", 1);

  df = vv - vv/2 - vc;
  if (vv < 8) df = 4 - vc;

  if (df>0)
  {
	shout( HIG "【表決】"+me->name()+"投票將" +victim->name()
			+"放出刑部大牢，還差"+sprintf("%d", df)+"票。\n" NOR);
	write( HIG "【表決】"+me->name()+"投票將" +victim->name()
			+"放出刑部大牢，還差"+sprintf("%d", df)+"票。\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
	shout( HIG "【表決】"+me->name()+"投票將" +victim->name()
			+"放出刑部大牢。"+victim->name()+"已經被放出刑部大牢了！\n" NOR);
	write( HIG "【表決】"+me->name()+"投票將" +victim->name()
			+"放出刑部大牢。"+victim->name()+"已經被放出刑部大牢了！\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(victim, inv[i]);
	}
	victim->delete("vote/juror");
	victim->delete("xkx_jail");
	victim->move("/d/city/wumiao");
  } 
  
  return 1;
}

