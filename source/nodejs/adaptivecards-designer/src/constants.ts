export const defaultPayload: string = `{
	"$schema": "http://adaptivecards.io/schemas/adaptive-card.json",
	"type": "AdaptiveCard",
	"version": "1.0",
	"body": [
		{
			"type": "Container",
			"items": [
				{
					"type": "TextBlock",
					"text": "Publish Adaptive Card schema",
					"weight": "bolder",
					"size": "medium"
				},
				{
					"type": "ColumnSet",
					"columns": [
						{
							"type": "Column",
							"width": "auto",
							"items": [
								{
									"type": "Image",
									"url": "https://pbs.twimg.com/profile_images/3647943215/d7f12830b3c17a5a9e4afcc370e3a37e_400x400.jpeg",
									"size": "small",
									"style": "person"
								}
							]
						},
						{
							"type": "Column",
							"width": "stretch",
							"items": [
								{
									"type": "TextBlock",
									"text": "Matt Hidinger",
									"weight": "bolder",
									"wrap": true
								},
								{
									"type": "TextBlock",
									"spacing": "none",
									"text": "Created {{DATE(2017-02-14T06:08:39Z,SHORT)}}",
									"isSubtle": true,
									"wrap": true
								}
							]
						}
					]
				}
			]
		},
		{
			"type": "TextBlock",
			"text": "Below is an ActionSet element"
		},
		{
			"type": "ActionSet",
			"actions": [
				{
					"type": "Action.ShowCard",
					"title": "Set due date",
					"card": {
						"type": "AdaptiveCard",
						"body": [
							{
								"type": "Input.Date",
								"id": "dueDate",
								"title": "Select due date"
							},
							{
								"type": "Input.Text",
								"id": "comment",
								"isMultiline": true,
								"placeholder": "Add a comment"
							}
						],
						"actions": [
							{
								"type": "Action.OpenUrl",
								"title": "OK",
								"url": "http://adaptivecards.io"
							}
						]
					}
				},
				{
					"type": "Action.OpenUrl",
					"title": "View",
					"url": "http://adaptivecards.io"
				}
			]					
		},
		{
			"type": "Container",
			"items": [
				{
					"type": "TextBlock",
					"text": "Now that we have defined the main rules and features of the format, we need to produce a schema and publish it to GitHub. The schema will be the starting point of our reference documentation.",
					"wrap": true
				},
				{
					"type": "FactSet",
					"facts": [
						{
							"title": "Board:",
							"value": "Adaptive Card"
						},
						{
							"title": "List:",
							"value": "Backlog"
						},
						{
							"title": "Assigned to:",
							"value": "Matt Hidinger"
						},
						{
							"title": "Due date:",
							"value": "Not set"
						}
					]
				}
			]
		}
	],
	"actions": [
		{
			"type": "Action.ShowCard",
			"title": "Set due date",
			"card": {
				"type": "AdaptiveCard",
				"body": [
					{
						"type": "Input.Date",
						"id": "dueDate",
						"title": "Select due date"
					},
					{
						"type": "Input.Text",
						"id": "comment",
						"isMultiline": true,
						"placeholder": "Add a comment"
					}
				],
				"actions": [
				    {
				        "type": "Action.OpenUrl",
						"title": "OK",
						"url": "http://adaptivecards.io"
			        }
				]
			}
		},
		{
			"type": "Action.OpenUrl",
			"title": "View",
			"url": "http://adaptivecards.io"
		}
	]
}`;
