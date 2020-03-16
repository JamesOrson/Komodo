using Komodo.Core;
using Komodo.Core.ECS.Components;
using Komodo.Core.Engine.Graphics;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Common.Behaviors
{
    public class ModelStartupBehavior : BehaviorComponent
    {
        #region Constructors
        public ModelStartupBehavior() : base()
        {
        }
        #endregion Constructors

        #region Members

        #region Public Members
        public bool IsInitialized
        {
            get
            {
                return this._isInitialized;
            }
        }
        #endregion Public Members

        #region Protected Members
        private bool _isInitialized { get; set; }
        #endregion Protected Members

        #region Private Members
        #endregion Private Members

        #endregion Members

        #region Member Methods

        #region Public Member Methods
        public override void Update(GameTime gameTime)
        {
            if (!_isInitialized)
            {
                _isInitialized = true;
                var loadedTexture = KomodoGame.Content.Load<Texture2D>("player/idle/player_idle_01");
                Parent.AddComponent(
                    new ModelComponent("models/cube")
                    {
                        Texture = new KomodoTexture(loadedTexture)
                    }
                );
                Parent.Scale = new KomodoVector3(20f, 20f, 20f);
            }
            Parent.Rotation += new KomodoVector3(0f, 0f, 0.001f);
        }
        #endregion Public Member Methods

        #region Protected Member Methods
        #endregion Protected Member Methods

        #region Private Member Methods
        #endregion Private Member Methods

        #endregion Member Methods
    }
}