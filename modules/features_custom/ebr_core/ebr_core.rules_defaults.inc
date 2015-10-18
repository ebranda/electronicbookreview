<?php
/**
 * @file
 * ebr_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ebr_core_default_rules_configuration() {
  $items = array();
  $items['rules_notify_editors_of_new_gloss'] = entity_import('rules_config', '{ "rules_notify_editors_of_new_gloss" : {
      "LABEL" : "Notify editors of new gloss",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "USES VARIABLES" : { "gloss_node" : { "label" : "Gloss node", "type" : "node" } },
      "ACTION SET" : []
    }
  }');
  $items['rules_notify_editors_of_new_pending_gloss'] = entity_import('rules_config', '{ "rules_notify_editors_of_new_pending_gloss" : {
      "LABEL" : "Notify editors of new pending gloss",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "notify_editors_of_new_pending_gloss" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : { "node_insert--gloss" : { "bundle" : "gloss" } },
      "IF" : [ { "NOT node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "A new gloss has been created that needs editorial review.",
            "message" : "Go here to read and approve the gloss: \\u003C?php echo _ebr_gloss_url($node, TRUE); ?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_editors_of_new_published_gloss'] = entity_import('rules_config', '{ "rules_notify_editors_of_new_published_gloss" : {
      "LABEL" : "Notify editors of new published gloss",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "notify_editors_of_new_published_gloss" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : { "node_insert--gloss" : { "bundle" : "gloss" } },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "A new gloss has been created - no further action",
            "message" : "A new gloss has been created - no further action is required. Read the gloss here: \\u003C?php echo _ebr_gloss_url($node, TRUE); ?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_send_essay_status_report'] = entity_import('rules_config', '{ "rules_send_essay_status_report" : {
      "LABEL" : "Send essay status report",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_switch_user", "views_rules", "php", "rules", "rules_scheduler" ],
      "ACTION SET" : [
        { "rules_switch_user_action_switch_to" : { "account" : "1" } },
        { "views_rules_collect_rows" : {
            "USING" : { "views_rules_display" : "essay_status_report:views_rules_1" },
            "PROVIDE" : {
              "states" : { "states" : "List of Workflow states" },
              "counts" : { "counts" : "List of essay counts in this state" }
            }
          }
        },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4", "7" : "7" } },
            "subject" : "Essay workflow status report",
            "message" : "Counts for all unpublished essays as of \\r\\n\\u003C?php echo date(\\u0027l jS \\\\of F Y h:i:s A\\u0027); ?\\u003E:\\r\\n\\r\\n\\u003C?php\\r\\nfor ($i=0; $i\\u003Ccount($states); $i++) {\\r\\n\\t$state = $states[$i];\\r\\n\\t$count = $counts[$i];\\r\\n\\techo \\u0027  \\u0027 . $state . \\u0027: \\u0027 . $count . \\u0027 essay\\u0027.($count == 1 ? \\u0027\\u0027 : \\u0027s\\u0027);\\r\\n\\techo \\u0022\\\\n\\u0022;\\r\\n}\\r\\n?\\u003E\\r\\n\\r\\nSummary report is below. View the full report at \\u003C?php global $base_url; echo $base_url . \\u0027\\/essay-status-report\\u0027; ?\\u003E\\r\\n\\r\\n\\r\\n\\u003C?php\\r\\nif (function_exists(\\u0027ebr_get_essay_status_report_as_text\\u0027))\\r\\n\\techo ebr_get_essay_status_report_as_text();\\r\\nelse\\r\\n\\tdrupal_set_message(\\u0027Undefined function: ebr_get_essay_status_report_as_text (Is ebr.module enabled and updated?)\\u0027, \\u0027error\\u0027);\\r\\n?\\u003E",
            "from" : "Electronic Book Review \\u003Cclc@mail.wvu.edu\\u003E"
          }
        },
        { "rules_switch_user_action_switch_back" : [] },
        { "schedule" : {
            "component" : "rules_send_essay_status_report",
            "date" : "+1 week",
            "identifier" : "Send essay status report"
          }
        }
      ]
    }
  }');
  $items['rules_trigger_workflow_state_update_email_scheduler'] = entity_import('rules_config', '{ "rules_trigger_workflow_state_update_email_scheduler" : {
      "LABEL" : "Trigger workflow state update email scheduler",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "workflow_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "8" : "8" } } } }
      ],
      "DO" : []
    }
  }');
  return $items;
}
