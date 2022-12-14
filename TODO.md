# TODO

## Open

There are some hosts that keep returning 400 Bad Request to snac posts (e.g. hachyderm.io). I've investigated but still don't know where's the problem.

Add support for Update + Note on input.

Add a user option to ignore all Announces from everybody.

Add domain/subdomain flexibility according to https://codeberg.org/grunfink/snac2/issues/3

Add support for uploading the avatar, instead of needing an URL to an image. As a kludgy workaround, you can post something with an attached image, copy the auto-generated URL and use it. You can even delete the post, as attached images are never deleted (I said it was kludgy).

Add (back) the possibility to attach an image by URL.

With this new disk layout, hidden posts (and their children) can be directly skipped (are there any other implications?).

## Wishlist

Implement the ActivityPub C2S (Client to Server) API: (https://www.w3.org/TR/activitypub/#client-to-server-interactions).

Implement HTTP caches (If-None-Match / ETag).

The 'history' pages are just monthly HTML snapshots of the local timeline. This is ok and cheap and easy, but is problematic if you e.g. intentionally delete a post because it will remain there in the history forever. If you activate local timeline purging, purged entries will remain in the history as 'ghosts', which may or may not be what the user wants.

Implement hashtags. They are not very useful, as they can only be implemented as instance-only (not propagated), but it may help classifiying your own posts.

Implement bulleted lists. Mastodon is crap and won't show them, but other implementations (Friendica, Pleroma) will do.

## Closed

Start a TODO file (2022-08-25T10:07:44+0200).

Change the layout to be multi-user (2022-08-25T16:23:17+0200).

Read address:port from server.json (2022-08-26T09:14:08+0200).

Added an installation setup (2022-08-26T09:39:46+0200).

Purge timeline entries older than a configurable value (2022-08-26T13:15:21+0200).

Move all the interactive code (like initdb()) to a special source file that is only imported on demand (2022-08-26T18:08:05+0200).

Add Basic Authentication for /admin* (2022-08-28T18:55:05+0200).

Add unfollow (2022-08-28T19:59:29+0200).

Generate the /outbox, unpaged, of the 20 latest entries, like what honk does (2022-08-29T14:29:48+0200).

If a user serves a static style.css file, it's embedded in the HTML (2022-08-29T14:52:57+0200).

Filter note texts through a Markdown-like filter (2022-08-29T21:06:47+0200).

If a `Like` or `Announce` is received from the exterior but the object is of a different user in the same instance, when the object is resolved a loop happens SNAC/activitypub.py:506: (2022-08-30T10:03:03+0200).

Ensure that likes and boosts are applied to the object instead of the container. More on this: for Mastodon, we're showing the '.../activity' link instead of the proper Note (2022-08-30T11:57:31+0200).

Fix signature checks (2022-08-30T18:32:22+0200).

Add @user@host citation in notes (2022-08-31T10:42:46+0200).

Add a snac.L() localisation function.

Add an `adduser` command-line option (2022-08-31T19:02:22+0200).

`Accept` + `Follow` types should not be trusted (anyone can be followed by sending them) (2022-09-01T08:49:57+0200).

It happened twice that a reply-to Note is lost (from the web) (2022-09-02T12:31:49+0200).

Implement the like button (2022-09-02T19:28:04+0200).

Implement the boost button (2022-09-02T19:28:04+0200).

Implement the follow button (2022-09-02T19:28:04+0200).

Implement the unfollow button (2022-09-02T19:28:04+0200).

Implement the mute button (2022-09-02T19:28:04+0200).

Don't write messages in the timeline if they are already there (2022-09-03T19:14:58+0200).

Implement the Emoji tags in Notes (2022-09-03T22:14:56+0200).

Implement the 'one page' timeline (2022-09-04T05:41:07+0200).

Re-implement the renaming of updated messages in the local time (2022-09-04T05:58:51+0200).

Add support for a server `greeting.html` that will be returned when the server URL is queried, with a special mark to insert the user list (2022-09-05T10:05:21+0200).

Implement HTML caches for both timelines (2022-09-05T13:45:27+0200).

Implement a history for the local timeline (2022-09-05T14:20:15+0200).

Disable the Boost button for private messages (2022-09-05T19:32:15+0200).

Implement a user config page, where they can change their name, avatar, bio and password (2022-09-05T22:29:26+0200).

Also replace Emoji tags in people's names (2022-09-05T23:00:29+0200).

Implement `Delete` + `Tombstone` on input (2022-09-07T09:20:20+0200).

Implement `Delete` + `Tombstone` on output (2022-09-07T09:42:09+0200).

Entries in the local timeline appear again after being shown in a thread. Try implementing an 'already shown entries' set (2022-09-07T11:21:52+0200).

The Delete button doesn't work for Likes and Announces (it points to the wrong message id) (2022-09-07T15:46:29+0200).

Document `server.json` in the admin manual (2022-09-08T11:01:43+0200).

Document the command-line interface in the user manual (2022-09-08T11:26:11+0200).

Document the web interface in the user manual (2022-09-08T14:00:11+0200).

Enable back the caches (2022-09-08T19:12:51+0200).

Do not show `Like` or `Boost` buttons if that was already done (2022-09-12T19:29:04+0200).

Parents of a parent should also move up the timeline (2022-09-13T22:41:23+0200).

Started the **real** version (developed in C instead of Python) (2022-09-19T20:40:42 2022 +0200).

When a new note has an in-reply-to, also download it (2022-09-24T07:20:16+0200).

After 'Unfollow' or 'MUTE', the timeline should be rebuilt (regardless of the cached version) (2022-10-01T20:27:00+0200).

Should this user's notes with in_reply_to be resolved inside the object? (2022-10-01T20:27:52+0200).

Should admirations download the admired object into the timeline instead of resolving? (2022-10-01T20:27:52+0200).

Add a user configuration flag to hide likes from the timeline (2022-10-01T20:27:52+0200).

Implement an input queue (2022-10-01T20:27:52+0200).

Refactor HTML rendering because it's a mess and write build_timeline(), that generates a big structure with everything to show in a timeline, to be passed to the HTML renderer (2022-10-01T20:27:52+0200).

Implement the helper thread (2022-10-01T20:56:46+0200).

Implement the user-setup web interface (2022-10-02T17:45:03+0200).

Implement the local timeline cache (2022-10-02T18:17:27+0200).

Implement the h/ (history) path (2022-10-02T18:23:24+0200).

Import the man pages (2022-10-03T21:38:23+0200).

Implement the 'init' command-line option (2022-10-04T09:55:56+0200).

Implement the 'adduser' command-line option  (2022-10-04T09:55:56+0200).

Implement the purge (2022-10-04T18:52:00+0200).

Implement the citations as @user@host in the reply textareas (2022-10-06T19:08:39+0200).

Show dates in local time and not UTC (2022-10-06T19:45:53+0200).

Embed videos (2022-10-10T08:25:39+0200).

Implement image attachments (2022-10-10T09:04:22+0200).

build_mentions() should not query the webfinger (and it's disabled by now); process_message() should 'complete' the tag Mentions that don't include a host (2022-10-10T09:45:57+0200).

Process the timeline html from a dedicated thread (2022-10-10T20:08:35+0200).

Implement the s/ (static) path (2022-10-11T08:52:09+0200).

Implement image upload (2022-10-16T20:08:16+0200).

Implement the :emojis: in actor names and messages (2022-10-17T12:12:58+0200).

Implement notification by email of private messages (2022-10-28T21:17:27+0200).

Make local likes / announces more visible (2022-10-28T21:18:41+0200).

Implement sensitive messages: they have a non-empty `summary` field and a `sensitive` field set to *true* (2022-10-30T06:19:13+0100).

Add web interface for sending private messages (they can already be answered like normal replies) (2022-11-02T11:07:40+0100).

Add web interface for the list of people being followed and who follows us (2022-11-02T11:07:40+0100).

Add a 'Hide' button, to stop showing a post and its children (2022-11-04T09:45:39+0100).

Add a purge timeout also for the local timeline (2022-11-12T08:32:56+0100).

Add a switch for sensitive posts (2022-11-16T12:17:50+0100).

Add an RSS to the local timeline (2022-11-18T11:43:54+0100).

Dropping on input those messages that have their parent hidden is not a good idea, as children of *these* dropped messages will pass unharmed (2022-11-28T11:34:56+0100).

Idea for a new disk layout: timelines stored like in git (2 character directories and then the md5.json inside); one append-only index with entry ids, read backwards (easy because md5 binary ids have a constant size); children lists as append-only files stored inside the timeline directories with almost the same names as the parent entry; liked-by and announced-by lists as append-only files of actor ids. No _snac metadata inside the message (But, what about the referrer? With this layout, do I need it?). The instance storage may even be global, not per user; this could help in very big instances (but will this be a use-case for snac? not probably) (2022-12-04T06:49:55+0100).

Add this pull request https://codeberg.org/grunfink/snac2/pulls/9 (2022-12-05T12:12:19+0100).

Add an ?skip=NNN parameter to the admin page, to see older timeline (2022-12-08T08:41:11+0100).

Now that we have the 2.7 layout and Likes and Announces don't move the conversations up, finally fix the ugly # positioning (2022-12-08T08:41:27+0100).

Disable the 'Boost' button for non-public messages (technically they can be Announced, but shouldn't) (2022-12-08T08:46:24+0100).
